#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P, P>PP;
typedef pair<PP, PP>PPPP;
struct edge { int to; int cost; };
int kj[200006], kji[200006];
int modpow(int n, int x, int mod) {
	if (!x)return 1;
	int res = modpow(n*n%mod, x / 2, mod);
	if (x & 1)res = res*n%mod;
	return res;
}
int comb(int r, int c) {
	return kj[r] * kji[c] % mod * kji[r - c] % mod;
}

signed main() {
	kj[0] = 1;
	rep(i, 200003) {
		kj[i + 1] = kj[i] * (i + 1);
		kj[i + 1] %= mod;
	}
	rep(i, 200003)kji[i] = modpow(kj[i], mod - 2, mod);
	int n, m, k; cin >> n >> m >> k;
	int sumn = 0, summ = 0;
	rep(i, n + 1) {
		sumn += i*m*m*(n - i);
		sumn %= mod;
	}
	rep(i, m+1) {
		summ += i*n*n*(m - i);
		summ %= mod;
	}

	cout <<( (summ + sumn) % mod)*comb(m*n - 2, k - 2) % mod << endl;
}