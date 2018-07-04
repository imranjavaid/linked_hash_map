
test: test.cpp
	clang++ -Wall -std=c++14 test.cpp -o test

clean:
	rm test
