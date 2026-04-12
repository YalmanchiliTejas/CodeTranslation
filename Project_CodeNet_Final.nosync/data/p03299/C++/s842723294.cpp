#pragma warning (disable:4996)
#include"bits/stdc++.h"
#include<cassert>
#define int long long
#define MRE assert(0);
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e17;
typedef pair<int, int> P;
struct rect {
	int L, R, H;
};
int n; 
int h[105];
int dp1[105][105], dp2[105][105];
int modpow(int a, int x) {
	int res = 1;
	while (x) {
		if (x & 1)res = res*a%mod;
		a = a*a%mod;
		x >>= 1;
	}
	return res;
}

void memo(int l, int r) {
	if (dp1[l][r] != -1)return;
	vector<P>V;
//	cout << l << ' ' << r << endl;

	int idx = l, mn = inf;
	for (int i = l; i <= r; i++)mn = min(mn, h[i]);
	int idx2 = l;

	while (1) {
		while (idx2<=r&&h[idx2] == mn)idx2++;
		if (idx2 > r)break;
		int idx3 = idx2;
		while (idx3<=r&&h[idx3] != mn)idx3++;
		V.push_back(P(idx2, idx3-1));
		idx2 = idx3 + 1;
	}

	if (V.size()) {//適切なマージ
		vector<P>V2;
		rep(j, V.size()) {
			memo(V[j].first, V[j].second);
			V2.push_back(P(dp1[V[j].first][V[j].second], dp2[V[j].first][V[j].second]));
		}
		int m = 0;
		for(int i=l;i<=r;i++)if (h[i] == mn)m++;
		int sum = 1, sum2 = 2;
		int H = h[r + 1];
		if (l)H = max(H, h[l - 1]);
		H = mn - H;
		rep(i, V2.size()) {
			sum *= V2[i].first + 2 * V2[i].second;
			sum %= mod;
			sum2 *= V2[i].second;
			sum2 %= mod;
		}
		sum = sum*modpow(2, m) % mod;
		int T = (sum + mod - sum2) % mod;
		sum2 = sum2*modpow(2, H-1) % mod;
		dp1[l][r] = T;
		dp2[l][r] = sum2;
//		cout << l << ' ' << r << ' ' << T << ' ' << sum2 << ' ' << H << endl;
	}
	else {
		int H = h[r + 1];
		if (l)H = max(H, h[l - 1]);
		int t = (modpow(2, r - l + 1) + mod - 2) % mod;
		int u = modpow(2, h[l]-H);
		dp1[l][r] = t;
		dp2[l][r] = u;
	}
}


signed main() {
	cin >> n;
	rep(i, n)cin >> h[i];
	
	/*
	int cnt = 0;
	rep(i, n - 1) {
		if (h[i]<h[i + 1] && h[i + 1]>h[i + 2]) {
			cnt += h[i + 1] - max(h[i], h[i + 2]);
			h[i + 1] = max(h[i], h[i + 2]);
		}
	}
	if (h[0] > h[1]) {
		cnt += h[0] - h[1];
		h[0] = h[1];
	}
	cnt %= mod;
	rep(i, n) {
		if (i)cout << ' '; cout << h[i];
	}cout << endl;
	*/

	rep(i, n)rep(j, n)dp1[i][j] = dp2[i][j]= -1;
	memo(0, n - 1);
	cout << (dp1[0][n - 1] + dp2[0][n - 1])%mod << endl;
}