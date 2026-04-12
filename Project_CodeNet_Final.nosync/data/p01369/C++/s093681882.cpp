#include<iostream>
#include<string>
using namespace std;

int main() {
	bool boad[26] = {};
	for (int i = 0; i < 7; ++i)boad[i];
	for (int i = 7; i < 16; ++i)boad[i]++;
	for (int i = 16; i < 20; ++i)boad[i];
	for (int i = 20; i < 21; ++i)boad[i]++;
	for (int i = 21; i < 24; ++i)boad[i];
	boad[24]++; boad[25];
	string s;
	while (cin >> s, s != "#") {
		int sup = s.size() - 1, ans = 0;
		for (int i = 0; i < sup; i++) {
			if (boad[s[i] - 'a'] != boad[s[i + 1] - 'a'])ans++;
		}
		cout << ans << endl;
	}
}