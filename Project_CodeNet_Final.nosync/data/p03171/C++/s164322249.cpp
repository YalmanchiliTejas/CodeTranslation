// in the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define ll long long
#define double long double
#define sz(x) ((int) (x.size()))

#define fr first
#define se second

#define inf 1e9
#define max_n 123456
#define mod 1000000007

ll add(ll a, ll b) {
	a += b;
	if(a >= mod) return a - mod;
	return a;
}

ll mul(ll a, ll b) {
	a *= b;
	if(a >= mod) return a % mod;
	return a;
}

ll power(ll a, ll b) {
	ll p = 1;
	while(b) {
		if(b&1) p = mul(p, a);
		a = mul(a, a);
		b /= 2;
	}
	return p;
}

int n;
ll a[3333];
ll dp[3333][3333][2];

ll memo(int i, int j, int t) {
	if(i == j) {
		if(t == 0) return a[i];
		return -a[i];
	}
	if(dp[i][j][t] != -1) return dp[i][j][t];
	ll res;
	if(t == 0) {
		res = max(memo(i+1, j, 1) + a[i], memo(i, j-1, 1) + a[j]);
	}
	else {
		res = min(memo(i+1, j, 0) - a[i], memo(i, j-1, 0) - a[j]);
	}
	return dp[i][j][t] = res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << memo(0, n-1, 0) << endl;
	return 0;
}