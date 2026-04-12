#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;
const long long inf = 1ll << 61;
const long long mod = 1000000007;

signed main() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	if (s[0] == 'B') {
		rep(i, m) {
			if (s[i] == 'R')s[i] = 'B'; else s[i] = 'R';
		}
	}
	vector<int>r, b;
	char now = 'R'; int cnt1 = 0;
	s.push_back('A');
	rep(i, m+1) {
		if (now == s[i])cnt1++;
		else {
			if (now == 'R')r.push_back(cnt1);
			else b.push_back(cnt1);
			now = s[i];
			cnt1 = 1;
		}
	}
	s.pop_back();

	if (b.empty()) {//全部一緒
		vector<int>L(200005);
		L[0] = 2; L[1] = 1;
		rep(i, 200002)L[i + 2] = (L[i] + L[i + 1]) % mod;
		cout << L[n] << endl;
		return 0;
	}

	if (n & 1) {
		cout << 0 << endl; return 0;
	}
	else {
		int MR = r[0];
		if (MR & 1)MR += 2;
		else MR += 1;
		rep(i,r.size()-1){
			int e = r[i];
			if (e & 1)MR = min(MR, e);
		}
		if (r.size() == b.size()) {
			int e = r[r.size() - 1];
			if(e&1)MR = min(MR, e);
		}
		MR = (MR + 1) / 2;
		vector<int>dp(200005);
		int s = 1, as = 1;
		dp[1] = 1;
		for (int i = 2; i <= MR; i++) {
			dp[i] = (as + i) % mod;
			as = (as + dp[i]) % mod;
		}
		for (int i = MR + 1; i <= n; i++) {
			dp[i] = as;
			as += dp[i];
			as -= dp[i - MR];
			as = (as + mod) % mod;
		}
		cout << (dp[n/2]*2)%mod << endl;
	}
}