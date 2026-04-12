#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = (int)(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl

using namespace std;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
    int x(0), sgn(1); char ch(getchar());
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
    for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
    return x * sgn;
}

void File() {
#ifdef zjp_shadow
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
#endif
}

const int N = 2e5 + 1e3;

int n;

pair<int, int> a[N];

multiset<int> R, B;

#define Max(S) *S.begin()
#define Min(S) *S.rbegin()

int main() {

	File();

	n = read();
	For (i, 1, n) {
		int x = read(), y = read(); if (x > y) swap(x, y);
		B.insert(x); R.insert(y); a[i] = make_pair(x, y);
	}
	long long ans = 1ll * (Max(R) - Min(R)) * (Max(B) - Min(B));

	sort(a + 1, a + n + 1);
	For (i, 1, n) {
		B.erase(B.find(a[i].first)); R.insert(a[i].first);
		R.erase(R.find(a[i].second)); B.insert(a[i].second);
		chkmin(ans, 1ll * (Max(R) - Min(R)) * (Max(B) - Min(B)));
	}
	printf ("%lld\n", ans);

	return 0;

}