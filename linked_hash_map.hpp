#ifndef LINKED_HASH_MAP_HPP
#define LINKED_HASH_MAP_HPP

#include <unordered_map>
#include <list>
#include <utility>

template <class K, class V>
class linked_hash_map {
private:
	typedef typename std::list<K const>::iterator list_iterator;
	std::unordered_map< K, std::pair<V, list_iterator > > hash; 
	std::list<K const> ls;
public:
	const int size() noexcept { return hash.size(); }
	const bool empty() noexcept { return hash.empty(); }
	
	void insert(std::pair<K,V>&& kv) {
		auto const p = hash.find(kv.first);
		if (p != hash.end()) {
			p->second.first = std::move(kv.second);
		} else {
			auto const it = ls.insert(ls.end(), kv.first);
			try {
				hash.insert( std::make_pair(std::move(kv.first), std::make_pair(std::move(kv.second), it)));
			}
			catch (...) {
				ls.erase(it);
				throw;
			}
		}
	}
	void insert(std::pair<K,V> const& kv) {
		auto const p = hash.find(kv.first);
		if (p != hash.end()) {
			p->second.first = std::move(kv.second);
		} else {
			ls.push_back(kv.first);
			try {
				auto it = ls.end(); --it;
				hash.insert( std::make_pair(kv.first, std::make_pair(kv.second, it)));
			}
			catch (...) {
				ls.pop_back();
				throw;
			}
		}
	}
	void erase(K const& key) {
		auto const p = hash.find(key);
		if (p != hash.end()) {
			ls.erase(p->second.second);
			hash.erase(p);
		}
	}
	void eraseEldest() {
		if(!hash.empty()) {
			hash.erase(ls.front());
			ls.pop_front();
		}
	}
	void eraseNewest() {
		if(!hash.empty()) {
			hash.erase(ls.back());
			ls.pop_back();
		}
	}
	V& at(K const& key) {
		return hash.at(key).first;
	}
	V const& at(K const& key) const {
		return hash.at(key).first;
	}
	V& operator[](K const& key) {
		return hash[key].first;
	}
	V const& operator[](K const& key) const {
		return hash[key].first;
	}
	std::list<K const> keyList() {
		return ls;
	}
};

#endif