#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int n, m;
vv(int) G(n, vector<int>());
int ans = 0;

void	dfs(int now, vector<bool> check)
{
	check[now] = 1;
	for (int i = 0; i < n; ++i)
	{
		if (check[i] == 0)
			break ;
		if (i == n-1)
		{
			++ans;
			return ;
		}
	}
	for (auto v: G[now])
	{
		if (check[v])
			continue ;
		dfs(v, check);
	}
}

int		main(void)
{
	cin >> n >> m;
	G.assign(n, vector<int>());

	vector<bool> check(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, check);
	cout << ans << endl;
}

