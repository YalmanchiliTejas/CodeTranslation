#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 200005;

int n, mnr = 1 << 30, mnb = 1 << 30, cur = 1 << 30, mxr = 0, mxb = 0;
pii a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		a[i].xx = Read(), a[i].yy = Read();
		if (a[i].xx > a[i].yy)
			swap(a[i].xx, a[i].yy);
		mnr = min(mnr, a[i].xx), mxr = max(mxr, a[i].xx);
		mnb = min(mnb, a[i].yy), mxb = max(mxb, a[i].yy);
	}
	sort(a + 1, a + n + 1);
	LL ret = 1LL * (mxr - mnr) * (mxb - mnb);
	for (int i = 1; i <= n; i ++)
		ret = min(ret, 1LL * (mxb - mnr) * (mxr - min(cur, a[i].xx))), cur = min(cur, a[i].yy), mxr = max(mxr, a[i].yy);
	return printf("%lld\n", ret), 0;
}
