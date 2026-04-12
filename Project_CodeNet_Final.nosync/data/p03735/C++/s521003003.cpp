#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 1e9+7
#define N 200005
#define il inline
#define re register
#define tie0 cin.tie(0),cout.tie(0)
#define fastio ios::sync_with_stdio(false)
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;

template <typename T> inline void read(T &x) {
	T f = 1; x = 0; char c;
    for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for ( ; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x *= f;
}

struct Ball {
	ll x, y;
	bool operator < (const Ball &k) const {return x < k.x;}
} ball[N];

int n;
ll rmx, rmn, bmx, bmn, ans, res, ret;
ll x[N], y[N], mx[N], mn[N];

int main() {
	read(n);
	rmn = bmn = ret = INF;
	for (int i = 1; i <= n; ++i) {
		read(x[i]), read(y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		ball[i].x = x[i], ball[i].y = y[i];
		rmx = max(rmx, x[i]), rmn = min(rmn, x[i]);
		bmx = max(bmx, y[i]), bmn = min(bmn, y[i]);
	}
	res = (rmx - rmn) * (bmx - bmn);
	sort(ball + 1, ball + 1 + n);
	mx[1] = mn[1] = ball[1].y; bmn = rmn;
	for (int i = 2; i <= n; ++i) {
		mx[i] = max(mx[i-1], ball[i].y);
		mn[i] = min(mn[i-1], ball[i].y);
		if (i != n) ret = min(ret, max(mx[i], ball[n].x) - min(mn[i], ball[i+1].x));
	}
	ret *= (bmx - bmn);
	ans = min(ret, res);
	printf("%lld", ans);
	return 0;
}
