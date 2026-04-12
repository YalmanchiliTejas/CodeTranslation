#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int Cmp[n][26] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			Cmp[i][(char)s[i][j] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		int Min = INF;
		for (int j = 0; j < n; j++) {
			Min = min(Min, Cmp[j][i]);
		}
		for (int k = 0; k < Min; k++) {
			char C = 'a' + i;
			cout << C;
		}
	}
	cout << endl;
	return 0;
}