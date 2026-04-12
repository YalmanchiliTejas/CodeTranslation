#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> s(N);
	for (int i = 0; i < N; ++i) { cin >> s[i]; }

	vector<vector<int>> v(N, vector<int>(26, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			int key = s[i][j] - 'a';
			v[i][key] += 1;
		}
	}
	
	string res = "";
	for (int i = 0; i < 26; ++i) {
		int cnt = 1e5;
		for (int j = 0; j < N; ++j) {
			cnt = min(cnt, v[j][i]);
		}
		if (cnt > 0) {
			char c = 'a' + i;
			string tmp(cnt, c);
			res += tmp;
		}
	}

	cout << res << endl;

	return 0;
}
