#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// by piano
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
const int maxn = 105;
const int MOD = 1000000007;
int bin[maxn], h[maxn], f[maxn][3];
int n, mx, res, base = 1;
 
inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}
 
pii solve(int l, int r, int base) {
	// printf("%d %d %d\n", l, r, base);
	int mn = MOD, cnt = 0;
	pii res = make_pair(0, 0), sub;
	rep (i, l, r)
		if (h[i] < mn) mn = h[i], cnt = 1;
		else if (h[i] == mn) cnt++;
	if (cnt == r - l + 1) {
		res.first = (power(2, r - l + 1) + MOD - 2) % MOD;
		res.second = power(2, mn - base - 1);
		//printf("%d %d %d  %d %d\n", l, r, base, res.fi, res.se);
		return res;
	}
	int remain = r - l + 1, last = 0, tmp = 1;
	int res0 = 1, res1 = 1;
	rep (i, l, r + 1)
		if (!last && h[i] > mn) last = i;
		else if (last && (i > r || h[i] == mn)) {
			remain -= i - last;
			sub = solve(last, i - 1, mn);
			res0 = 1LL * res0 * (sub.fi + 4LL * sub.se) % MOD;
			res1 = 2LL * res1 * sub.se % MOD;
			last = 0;
		}
	res0 = (res0 + MOD - res1) % MOD;
	res.fi = 1LL * res0 * power(2, remain) % MOD;
	res.fi = (res.fi + 1LL * res1 * (power(2, remain) + MOD - 2)) % MOD;
	res.se = 1LL * res1 * power(2, mn - base - 1) % MOD;
	//printf("%d %d %d  %d %d\n", l, r, base, res.fi, res.se);
	return res;
}
 
int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &h[i]);
	if (n == 1) {
		printf("%d\n", power(2, h[1]));
		return 0;
	}
	rep (i, 1, n)
		if (h[i] > h[i-1] && h[i] > h[i+1]) {
			base = 1LL * base * power(2, h[i] - max(h[i-1], h[i+1])) % MOD;
			h[i] = max(h[i-1], h[i+1]);
		}
	pii tmp = solve(1, n, 0);
	res = 1LL * base * (tmp.fi + 2LL * tmp.se) % MOD;
	printf("%d\n", res);
	return 0;
}