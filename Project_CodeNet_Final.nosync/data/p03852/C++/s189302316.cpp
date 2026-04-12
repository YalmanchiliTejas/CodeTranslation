#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

string vowels = "aeiou";

int main() {
	char c;
	cin >> c;

	string ans = vowels.find(c) == string::npos ? "consonant" : "vowel";
	cout << ans << endl;
	return 0;
}
