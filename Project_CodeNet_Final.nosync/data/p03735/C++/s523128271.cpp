#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
const int maxn = 2e5 + 10;
const ll inf = 1e18 + 10;
ll ans = inf;
int n, tot;
int xmin = 1e9 + 10, xmax, ymin = 1e9 + 10, ymax;
int a[maxn][2];
pii val[maxn], b[maxn << 1];;
struct cmp
{
	bool operator() (const pii & i, const pii & j)
	{
		if(a[i.first][i.second] != a[j.first][j.second]) return a[i.first][i.second] < a[j.first][j.second];
		return i.first < j.first || (i.first == j.first && i.second < j.second);
	}
};
bool cmpb (const pii & i, const pii & j)
{
	return a[i.first][i.second] < a[j.first][j.second] || (a[i.first][i.second] == a[j.first][j.second] && i.second < j.second);
}
set<pii, cmp> s;
void solve()
{
	if(b[1].first != b[tot].first) s.insert(mp(b[1].first, 1)), s.insert(mp(b[tot].first, 0));
	for(int i = 2; i < tot; ++i)
		if(b[i].second == 0)
			s.insert(b[i]);
	while(true)
	{
		ans = min(ans, 1ll * (a[s.rbegin()->first][s.rbegin()->second] - a[s.begin()->first][s.begin()->second]) * (ymax - xmin));
		auto x = *s.begin();
		if(x.first == tot || x.second == 1)
			break;
		s.erase(x);
		x.second = 1;
		s.insert(x);
	}
	s.clear();
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &val[i].first, &val[i].second);
		if(val[i].first > val[i].second) swap(val[i].first, val[i].second);
		xmin = min(xmin, val[i].first);
		xmax = max(xmax, val[i].first);
		ymin = min(ymin, val[i].second);
		ymax = max(ymax, val[i].second);
	}
	ans = min(ans, 1ll * (xmax - xmin) * (ymax - ymin));
	sort(val + 1, val + n + 1);
	for(int i = 1; i <= n; ++i) a[i][0] = val[i].first, a[i][1] = val[i].second;
	for(int i = 1; i <= n; ++i) b[++tot] = mp(i, 0), b[++tot] = mp(i, 1);
	sort(b + 1, b + tot + 1, cmpb);
	solve();
	printf("%lld\n", ans);
	return 0;
}
/*
7
10 4
11 28
24 22
8 6
4 28
8 22
11 11
*/