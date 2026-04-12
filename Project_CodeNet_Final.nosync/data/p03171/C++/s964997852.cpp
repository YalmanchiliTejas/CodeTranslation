#include<iostream>
using namespace std;

typedef long long ll;
const ll inf(1e14);
const int N(3009);


int n, m, ans;
ll a[N];
ll f[N][N][2];

ll dfs(int l, int r, int player)
{
	if (l > r) return 0;
	if (f[l][r][player] < inf) return f[l][r][player];
	if (player) f[l][r][player] = max(dfs(l + 1, r, !player) + a[l], dfs(l, r - 1, !player) + a[r]);
	else f[l][r][player] = min(dfs(l + 1, r, !player) - a[l], dfs(l, r - 1, !player) - a[r]);
	return f[l][r][player];
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[i][j][0] = f[i][j][1] = inf;
		}
	}
	cout<<dfs(1, n, 1)<<endl;
	return 0;
}