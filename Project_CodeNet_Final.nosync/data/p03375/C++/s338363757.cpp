#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 3010;

ll mod_pow(ll x, ll k, ll m) {
	ll res = 1;
	for (; k; x = x * x % m, k /= 2) {
		if (k & 1) {
			res = res * x % m;
		}
	}
	return res;
}

int N;
ll m;
ll dp[MN][MN];
ll comb[MN][MN];

int main() {
	cin >> N >> m;

	rep(i, MN) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % m;
		}
	}
    dp[0][0] = 1;
    for (int i = 1; i < MN; ++i) {
    	for (int j = 1; j < MN; ++j) {
            dp[i][j] += dp[i-1][j] * j;
            dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= m;
    	}
    }

	ll ret = 0;

	for (int p = 0; p <= N; ++p) {
		ll p2 = mod_pow(2, N - p, m);
		ll b2 = mod_pow(2, N - p, m-1);
		ll f2 = mod_pow(2, b2, m);
		ll t = 0;
		ll ac = 1;

		for (int num = 0; num <= p; ++num) {
			ll c = dp[p][num+1] * f2 % m * ac % m * (num+1) % m;
			t = (t + c) % m;
			c = dp[p][num] * f2 % m * ac % m;
			t = (t + c) % m;
			ac = ac * p2 % m;
		}

		t = t * comb[N][p] % m;

		if (p & 1) {
			t = m - t;
		}

		ret = (ret + t) % m;
	}

	cout << ret << endl;

	return 0;
}