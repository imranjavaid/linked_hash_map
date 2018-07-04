#include <iostream>
#include "linked_hash_map.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	linked_hash_map<string, int> lhm;
	lhm.insert(make_pair("foo", 42));
	lhm.insert(make_pair("bar", 99));
	lhm.insert(make_pair("bat", 19));
	lhm.insert(make_pair("baz", 25));
	cout << lhm.at("foo") << endl;
	lhm.insert(make_pair("foo", 77));
	cout << lhm.at("foo") << endl;
	cout << lhm["foo"] << endl;
	lhm.erase("bar");
	lhm.eraseEldest();
	cout << "size " << lhm.size() << endl;
	
	auto keys = lhm.keyList();
	cout << "keys: ";
	for (string s: keys) {
		cout << s << " " ;
	}
	cout << endl;
	cout << lhm.at("baz") << endl;
	cout << lhm["baz"] << endl;
	lhm.eraseEldest();
	keys = lhm.keyList();
	cout << "keys: ";
	for (string s: keys) {
		cout << s << " " ;
	}
	cout << endl;
}