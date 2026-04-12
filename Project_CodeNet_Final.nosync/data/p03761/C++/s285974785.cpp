#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string s[55];
string ans;
int cnt[55][26];
int n;

int main() {
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> s[i];
		for (int j=0; j<s[i].length(); ++j) {
			cnt[i][s[i][j]-'a']++;
		}
	}
	ans = "";
	for (int i=0; i<26; ++i) {
		int c = 100000;
		for (int j=1; j<=n; ++j) c = min(c, cnt[j][i]);
		for (int j=1; j<=c; ++j) ans += ('a'+i);
	}
	cout << ans << '\n';
	return 0;
}


