#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 200000 + 10000;
const int INF = 0x1f1f1f1f;

int n;
long long ans = 0;
int mn = INF, mx = -INF;
pair<int, int> s[MAXN];

void calc1()
{
	int rmx = -INF, bmn = INF;
	for(int i = 1; i <= n; i++)
		rmx = max(rmx, s[i].first), bmn = min(bmn, s[i].second);
	ans = (long long)(rmx - mn) * (mx - bmn);
}

void calc2()
{
	static int smn[MAXN], smx[MAXN];
	smn[0] = INF, smx[0] = -INF;
	for(int i = 1; i <= n; i++)
		smn[i] = min(smn[i - 1], s[i].second), smx[i] = max(smx[i - 1], s[i].second);
	for(int i = 2; i <= n; i++)
		ans = min(ans, (long long)(mx - mn) * (max(s[n].first, smx[i - 1]) - min(s[i].first, smn[i - 1])));
}

void solve()
{
	for(int i = 1; i <= n; i++)
		if(s[i].first > s[i].second)
			swap(s[i].first, s[i].second);
	sort(s + 1, s + n + 1);
	mn = s[1].first;
	for(int i = 1; i <= n; i++)
		mx = max(mx, s[i].second);
	calc1();
	calc2();
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;

	solve();

	cout << ans << endl;

	return 0;
}
