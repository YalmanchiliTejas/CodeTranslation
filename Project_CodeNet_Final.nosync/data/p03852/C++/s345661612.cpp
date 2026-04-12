#include <bits/stdc++.h>
using namespace std;



int main() {
	string s;
	cin >> s;
	string a = "aiueo";
	cout << (a.find(s)==string::npos?"consonant":"vowel") << endl;
}
