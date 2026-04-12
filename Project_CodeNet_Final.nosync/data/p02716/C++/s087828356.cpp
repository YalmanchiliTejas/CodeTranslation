#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
#define ls (rt << 1)
#define rs (rt << 1 | 1) 
typedef pair<int, int> pii; 
const ll mod = 1e9 + 7;
template <class T> T lowbit(T x){return ((x)&(-(x)));}
const int maxn = 2e5 + 10;
int n;
int a[maxn];
ll pre[maxn][2], suf[maxn][2], f[maxn][2];

void solve0()
{
	for(int i = 1; i <= n; ++i)
	{
		pre[i][0] = pre[i - 1][0];
		pre[i][1] = pre[i - 1][1];
		pre[i][i & 1] += a[i];
	}
	for(int i = n, j = 1; i; --i, ++j)
	{
		suf[i][0] = suf[i + 1][0];
		suf[i][1] = suf[i + 1][1];
		suf[i][j & 1] += a[i];
	}
	ll ans = -1e18;
	for(int i = 0; i <= n; i += 2)
		ans = max(pre[i][1] + suf[i + 1][1], ans);
	cout << ans << endl;
}
void solve1()
{
	for(int i = 1; i <= n; ++i)
	{
		pre[i][0] = pre[i - 1][0];
		pre[i][1] = pre[i - 1][1];
		pre[i][i & 1] += a[i];
	}
	for(int i = n, j = 1; i; --i, ++j)
	{
		suf[i][0] = suf[i + 1][0];
		suf[i][1] = suf[i + 1][1];
		suf[i][j & 1] += a[i];
	}
	for(int i = 2; i <= n + 1; i += 2)
	{
		f[i][0] = f[i - 2][0] + a[i - 1];
		f[i][1] = max(f[i - 2][0] + a[i], f[i - 2][1] + a[i]);
	}
	ll ans = -1e18;
	for(int i = 2; i <= n + 1; i += 2)
		ans = max(max(f[i - 2][0], f[i - 2][1]) + suf[i + 1][1], ans);
	cout << ans << endl;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(n % 2 == 0) solve0();
	else solve1();
	return 0;
}