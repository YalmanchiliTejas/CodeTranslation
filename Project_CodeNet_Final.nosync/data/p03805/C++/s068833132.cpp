/*
Hanit Banga
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 10;

bool g[N][N] = {0};

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}	

	int p = 1;
	vector <int> order;
	order.pb(1);
	for (int i = 2; i <= n; ++i)
	{
		order.pb(i);
		p *= (i - 1);
	}

	int ans = 0;
	auto second = order.begin();
	++second;
	while (p--)
	{
		bool path = true;
		for (int i = 1; i < n; ++i)
		{
			if (!g[order[i - 1]][order[i]])
			{
				path = false;
				break;
			}
		}

		if (path)
			++ans;

		next_permutation(second, order.end());
	}

	cout << ans;
}