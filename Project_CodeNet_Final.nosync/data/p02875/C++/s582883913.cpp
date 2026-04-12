#include "bits/stdc++.h"
#include<assert.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define MRE assert(0);
const int inf = 1e11;
const int mod = 998244353;
const int maxN = 10000003;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int kj[maxN], kji[maxN];
int rwa[maxN];
int modpow(int a, int x, int mod) {
	int res = 1;
	while (x) {
		if (x & 1)res = res*a%mod;
		x >>= 1;
		a = a*a%mod;
	}
	return res;
}
void setkj(int n) {
	kj[0] = 1;
	rep(i, n)kj[i + 1] = kj[i] * (i + 1) % mod;
	rep(i, n + 1)kji[i] = modpow(kj[i], mod - 2, mod);
}
int comb(int r,int c) {
	if (c<0 || r<c)return 0;
	return kj[r] * kji[c] % mod*kji[r - c] % mod;
}
void expr(int n) {
	int sum = 0;
	rep(a1, n + 1) {
		rep(b1, n + 1) {
			rep(a2, n + 1) {
				rep(b2, n + 1) {
					if (a1 + b1 <= n&&a2 + b2 <= n&&a1 + b2 <= n&&a2 + b1 <= n) {
						int c1 = n - a1 - b1, c2 = n - a2 - b2;
						sum += kj[n] * kj[n] % mod*kji[a1] % mod*kji[a2] % mod*kji[b1] % mod*kji[b2] % mod*kji[c1] % mod*kji[c2] % mod;
						cout << a1 << b1 << a2 << b2 << endl;
					}
				}
			}
		}
	}
	cout << sum << endl;
}
signed main() {
	int n; cin >> n;
	setkj(n);
	n /= 2;
	int sum = 0;
	for (int j = 1; j <= n; j++)rwa[j] = comb(n, j)*modpow(2, mod - 1 - j, mod) % mod;
	for (int j = 0; j <= n; j++)rwa[j + 1] += rwa[j];

	for (int i = 1; i <= n; i++) {
		int lj = n + 1 - i, rj = n;
		int res1 = rwa[rj] - rwa[lj - 1] + mod;
		res1 %= mod;
		sum += comb(n, i)*modpow(2, n + n - i, mod) % mod*res1%mod;
		sum %= mod;
	}
	/*
	rep(i, n + 1) {
		rep(j, n + 1) {
			if (i + j > n) {
				sum += comb(n, i)*comb(n, j) % mod*modpow(2, n*2 - i-j, mod);
			}
		}
	}*/
	sum = modpow(3, 2 * n, mod) - sum * 2 % mod;
	sum = (sum + mod) % mod;
	cout << sum << endl; 
}