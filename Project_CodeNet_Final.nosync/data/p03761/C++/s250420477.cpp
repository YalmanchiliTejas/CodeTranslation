#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int n; cin >> n;
	vector<string> S(n);
	rep(i, n)cin >> S[i];

	vector<vector<int>> cnt(n, vector<int>(26, 0));

	rep(i, n) {
		for (auto x : S[i]) {
			cnt[i][x - 'a']++;
		}
	}

	vector<int> tot(26, 0);
	rep(i, 26) {
		tot[i] = cnt[0][i];
		rep(j, n)tot[i] = min(tot[i], cnt[j][i]);
	}

	string ans = "";
	rep(i, 26) {
		while (tot[i] > 0) {
			ans.push_back('a' + i);
			tot[i]--;
		}
	}

	cout << ans << endl;

	return 0;
}