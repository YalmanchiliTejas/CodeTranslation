#include <iostream>
#include <cstdio>
using namespace std;

char c;
string s="aeiou";
int main() {
	cin >> c;
	cout << (s.find(c)<5 ? "vowel" : "consonant");
	return 0;
}
