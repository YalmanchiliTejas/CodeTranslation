#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a), i##_end_ = (b); i <= i##_end_; ++i)
#define drep(i, a, b) for(int i = (a), i##_end_ = (b); i >= i##_end_; --i)
#define clar(a, b) memset((a), (b), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug(s) debug("The massage in line %d, Function %s: %s\n", __LINE__, __FUNCTION__, s)
typedef long long LL;
typedef long double LD;
int read() {
    char ch = getchar();
    int x = 0, flag = 1;
    for(;!isdigit(ch); ch = getchar()) if(ch == '-') flag *= -1;
    for(;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x * flag;
}
void write(LL x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar(x % 10 + 48);
}

const int Maxn = 3009;
LL dp[Maxn][Maxn], n, a[Maxn];

void init() {
	n = read();
	rep (i, 1, n) a[i] = read();
}

LL calc(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r] != LLONG_MAX) return dp[l][r];
	LL &res = dp[l][r], step = (r - l + 1) % 2 == n % 2;
	if (step) {
		res = calc(l, r - 1) + a[r];
		res = max(res, calc(l + 1, r) + a[l]);
	} else {	
		res = calc(l, r - 1) - a[r];
		res = min(res, calc(l + 1, r) - a[l]);
	}
	return res;
}

void solve() {
	rep (r, 0, n) 
		rep (s, 0, n) dp[r][s] = LLONG_MAX;
	cout << calc(1, n) << endl;
}

int main() {
 //   freopen("AtcoderDpL.in", "r", stdin);
  //  freopen("AtcoderDpL.out", "w", stdout);

    init();
    solve();

#ifdef Qrsikno
    debug("\nRunning time: %.3lf(s)\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

