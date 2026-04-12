#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int c[26];
	for (int i = 0; i < 26; i++) c[i] = 50;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int d[26];
		for (int j = 0; j < 26; j++) d[j] = 0;
		for (int j = 0; j < s.size(); j++) {
			d[s[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			c[j] = min(c[j], d[j]);
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < c[i]; j++) {
			cout << (char) ('a' + i);
		}
	}
	return 0;
}
