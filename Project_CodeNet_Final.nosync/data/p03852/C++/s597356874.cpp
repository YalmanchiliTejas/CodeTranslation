#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	char  c = cin.get();
	auto s = string("aeiou");
	cout <<
		(any_of(s.begin(), s.end(), [c](char cc) {return c == cc; }) ? "vowel" : "consonant")
		<< endl;
}
