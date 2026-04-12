#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
typedef std::pair<ll, ll> ii;
typedef std::pair<ll, ii> i3;

const int ms = 100100;

int par[ms];

int get_par(int x)
{
	if(x == par[x])
		return x;
	else
		return par[x] = get_par(par[x]);
}

void make_union(int a, int b)
{
	a = get_par(a);
	b = get_par(b);
	par[b] = a;
}

int main()
{
	int n;
	while(std::cin >> n)
	{
		std::vector<ii> a, b;
		for(int i = 0; i < n; i++)
		{
			par[i] = i;
			int x, y;
			std::cin >> x >> y;
			a.push_back(ii(x, i));
			b.push_back(ii(y, i));
		}
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		std::priority_queue<i3, std::vector<i3>, std::greater<i3> > hp;
		for(int i = 1; i < n; i++)
		{
			hp.push(i3(a[i].first - a[i - 1].first, ii(a[i].second, a[i - 1].second)));
			hp.push(i3(b[i].first - b[i - 1].first, ii(b[i].second, b[i - 1].second)));
		}
		ll ans = 0;
		while(!hp.empty())
		{
			ii to = hp.top().second;
			int cost = hp.top().first;
			hp.pop();
			if(get_par(to.first) != get_par(to.second))
			{
				make_union(to.first, to.second);
				ans += cost;
			}
		}
		std::cout << ans << '\n';
	}
}