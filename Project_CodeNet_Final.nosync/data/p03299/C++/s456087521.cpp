/*
D棰橈細
缁欏畾n鍒楃殑鏂瑰潡
绗琲鍒楅珮搴i
鐜板湪瑕佹妸瀹冩煋鎴愮孩钃濅袱鑹?
瑕佹眰婊¤冻锛?
瀵逛簬浠绘剰涓€涓?*2鐨勫尯鍩燂紝鎭版湁2涓摑鑹诧紝2涓孩鑹?
闂柟妗堟暟
n<=100,h<=10^9
*/
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