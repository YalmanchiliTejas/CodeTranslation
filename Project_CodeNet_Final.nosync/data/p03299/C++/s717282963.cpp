/*
Dé¢˜ï¼š
ç»™å®šnåˆ—çš„æ–¹å—
ç¬¬iåˆ—é«˜åº¦hi
çŽ°åœ¨è¦æŠŠå®ƒæŸ“æˆçº¢è“ä¸¤è‰²
è¦æ±‚æ»¡è¶³ï¼š
å¯¹äºŽä»»æ„ä¸€ä¸ª2*2çš„åŒºåŸŸï¼Œæ°æœ‰2ä¸ªè“è‰²ï¼Œ2ä¸ªçº¢è‰²
é—®æ–¹æ¡ˆæ•°
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
int h[maxn], f[maxn][3];
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
	if (n==1){
		printf("%d\n",power(2,h[1]));
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

/*
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define add(a,b) (a+b>=MOD?a+=b-MOD:a+=b)
using namespace std;
typedef long long LL;

const int maxn = 105;
const int MOD = 1000000007;
int h[maxn], f[maxn][3];
int n, mx, res, base = 1;

inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &h[i]);
	rep (i, 1, n)
		if (h[i] > h[i-1] && h[i] > h[i+1]) {
			base = 1LL * base * power(2, h[i] - max(h[i-1], h[i+1]));
			h[i] = max(h[i-1], h[i+1]);
		}
	rep (i, 1, n) mx = max(mx, h[i]);
	res = power(2, mx + 1);		//æ²¡æœ‰ç›¸é‚»çš„ç›¸åŒçš„case
	int t = 0;
	rep (i, 1, n) {				//æžšä¸¾ç›¸åŒçš„æœ€å¤§å€¼
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		rep (j, 1, n)			//åˆ†ä¸‰ç§æƒ…å†µè®¨è®º
			if (j < i) {
				add(f[j][0], f[j-1][0]);
				if (h[j] <= h[i]) 
					add(f[j][1], f[j-1][0]);
				
				if (h[j] <= h[i])
					add(f[j][2], f[j-1][1]);
				
				add(f[j][0], f[j-1][2]);
				if (h[j] <= h[i]) {
					add(f[j][1], f[j-1][2]);
					add(f[j][2], f[j-1][2]);
				}
			}
			else if (j > i) {
				add(f[j][0], f[j-1][0]);
				if (h[j] < h[i]) 
					add(f[j][1], f[j-1][0]);
				
				if (h[j] < h[i])
					add(f[j][2], f[j-1][1]);
				
				add(f[j][0], f[j-1][2]);
				if (h[j] < h[i]) {
					add(f[j][1], f[j-1][2]);
					add(f[j][2], f[j-1][2]);
				}
			}
			else {
				add(f[j][1], f[j-1][0]);
				add(f[j][2], f[j-1][1]);
				add(f[j][1], f[j-1][2]);
				add(f[j][2], f[j-1][2]);
			}
		int tmp = (f[n][0] + f[n][2]) % MOD;
		t = (t + tmp) % MOD;
		printf("%d %d\n", i, tmp);
		res = (res + 1LL * tmp * power(2, mx - h[i] + 1)) % MOD;
	}
	printf("%d\n", t);
	res = 1LL * res * base % MOD;
	printf("%d\n", res);
	return 0;
}
*/