#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;  cin >> n;
	vector<string> S(n);
	for (int i = 0; i < n; i++) cin >> S[i];

	vector<vector<int>> cnt(n, vector<int>(26, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < S[i].length(); j++) {
			cnt[i][S[i][j] - 'a']++;
		}
	}

	vector<int> nAns(26);
	for (int i = 0; i < 26; i++) {
		int buf = n * 50;
		for (int j = 0; j < n; j++) {
			buf = min(buf, cnt[j][i]);
		}
		nAns[i] = buf;
	}

	string ans = "";
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < nAns[i]; j++) {
			ans += (char)('a' + i);
		}
	}
	cout << ans << endl;
}