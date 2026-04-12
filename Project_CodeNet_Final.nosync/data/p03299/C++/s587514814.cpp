#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = double;
const int maxn = 105, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a[maxn];
map<int, int> gp[maxn][maxn], fp[maxn][maxn];

//g - flipping pattern
//f - everything else
#define mul(x, y) ( (x) * 1ll * (y) % mod )

int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = mul(r, a);
		p >>= 1, a = mul(a, a);
	}
	return r;
}
int g(int l, int r, int w) {
	if(gp[l][r].count(w)) return gp[l][r][w];
	int mn = 1<<30;
	for(int i = l; i <= r; i++) mn = min(mn, a[i]);
	if(mn != w) {
		return gp[l][r][w] = mul(bp(2, mn-w), g(l, r, mn));
	}
	
	int ans = 1, len = 0;
	for(int i = l; i <= r; i++) {
		if(a[i] == w) {
			if(len) ans = ans * 1ll * g(i - len, i - 1, w + 1) % mod;
			len = 0;
		} else ++len;
	}
	if(len) ans = ans * 1ll * g(r + 1 - len, r, w + 1) % mod;
	gp[l][r][w] = ans * 2ll % mod;
	return gp[l][r][w];
}

int f(int l, int r, int w) {
	if(fp[l][r].count(w)) return fp[l][r][w];
	int mn = 1<<30;
	for(int i = l; i <= r; i++) mn = min(mn, a[i]);
	if(mn != w) {
		return gp[l][r][w] = f(l, r, mn);
	}
	
	int ans = 1, len = 0;
	for(int i = l; i <= r; i++) {
		if(a[i] == w) {
			if(len) ans = ans * 1ll * (2ll * g(i - len, i - 1, w + 1) + f(i - len, i - 1, w + 1)) % mod;
			ans = ans * 2ll % mod;
			len = 0;
		} else ++len;
	}
	if(len) ans = ans * 1ll * (2ll * g(r + 1 - len, r, w + 1) + f(r + 1 - len, r, w + 1)) % mod;
	fp[l][r][w] = (mod + ans - g(l, r, w)) % mod;
	return fp[l][r][w];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << (g(0, n-1, 1)+f(0, n-1, 1))%mod;
}
