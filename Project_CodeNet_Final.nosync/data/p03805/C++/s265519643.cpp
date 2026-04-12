#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
ll n, m;

bool check(const Graph &G, const vector<ll> &v)
{
	if (v[0] != 0) return false;

	vector<bool> seen(n, false);
	seen[0] = true; // start
	for (int i = 0; i < n-1; ++i)
	{
		ll current{v[i]};
		ll target{v[i+1]};
		
		bool flag{false};
		for (auto e : G[current])
			if (e == target) flag = true;

		if (!flag) return false;
		else seen[target] = true;

		flag = true;
		for (size_t i = 0; i < v.size(); ++i)
			if (!seen[i]) flag = false;
		if (flag) return true;
	}

	return false;
}

template <class Iterator>
void show(Iterator begin, Iterator end)
{
	for (; begin != end; ++begin)
		std::cout << *begin + 1 << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	cin >> n >> m;
	Graph G(n);

	for (ll i = 0; i < m; ++i)
	{
		ll a, b; cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<ll> v;
	for (ll i = 0; i < n; ++i)
		v.push_back(i);

	ll count{0};
	do
	{
		if (v[0] != 0) break;
		if (check(G, v))
		{
			++count;
//			show(v.begin(), v.end());
		}
	} while (next_permutation(v.begin(), v.end()));
	std::cout << count << std::endl;
}
