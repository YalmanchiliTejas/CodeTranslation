#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, al[50][26] = { 0 };
	string s[50];
	cin >> n;
	rep(i, n) {
		cin >> s[i];
		rep(j, s[i].size()) {
			al[i][s[i][j] - 'a']++;
		}
	}
	rep(i, 26) {
		const int INF = 1000;
		int cnt = 0;
		int mi = INF;
		rep(j, n) {
			mi = min(mi, al[j][i]);
		}
		rep(j, mi) cout << (char)(i + 'a');
	}
	cout << endl;
	return 0;
}