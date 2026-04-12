/************************************************
 * Au: Hany01
 * Email: hany01@foxmail.com
************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j) for (register int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for (register int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for (register int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define fir first
#define sec second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define Mod (1000000007)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 wozenmezhemecaia

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }

inline int read()
{
	register int _, __; register char c_;
    for (_ = 0, __ = 1, c_ = getchar(); c_ < '0' || c_ > '9'; c_ = getchar()) if (c_ == '-') __ = -1;
    for ( ; c_ >= '0' && c_ <= '9'; c_ = getchar()) _ = (_ << 1) + (_ << 3) + (c_ ^ 48);
    return _ * __;
}

inline void File()
{
#ifdef hany01
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
}

int main()
{
    File();
	LL n, k, t, Ans = 0, len;
	n = read(), k = read();
	For(b, k + 1, n) {
		t = (n + 1) / b;
		len = b - k;
		Ans += t * len;
		if ((t + 1) * b - len + 1 <= n + 1) Ans += (n + 1) - ((t + 1) * b - 1 - len + 1);
		if (!k) -- Ans;
	}
	cout << Ans;
    return 0;
}