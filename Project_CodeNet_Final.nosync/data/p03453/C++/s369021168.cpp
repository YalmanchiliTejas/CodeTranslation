#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

vector<vector<pair<int, nagai>>> g;

vector<nagai> d;
const nagai inf = 1e18;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (d[a] != d[b])
			return d[a] < d[b];
		return a < b;
	}
};

vector<nagai> dij(int from)
{
	d.assign(g.size(), inf);
	d[from] = 0;
	set<int, cmp> st;
	st.insert(from);
	while (st.size())
	{
		int x = *st.begin();
		st.erase(st.begin());
		for (auto p : g[x])
		{
			auto b = p.first;
			auto c = p.second;
			if (c + d[x] < d[b])
			{
				st.erase(b);
				d[b] = c + d[x];
				st.insert(b);
			}
		}
	}
	return d;
}

nagai mod = 1e9 + 7;

vector<nagai> cntways(vector<nagai>& d, vector<vector<int>>& g, int from)
{
	vector<nagai> ans(d.size());
	ans[from] = 1;
	vector<int> ord(d.size());
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b)
			{
				return d[a] < d[b];
			});
	for (int x : ord)
	{
		for (int y : g[x])
		{
			ans[y] += ans[x];
			if (ans[y] >= mod)
				ans[y] -= mod;
		}
	}
	return ans;
}

bool intersects(nagai a, nagai b, nagai c, nagai d)
{
	a = max(a, c);
	b = min(b, d);
	return b > a;
}

int main()
{
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s, --t;
	g.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	auto ds = dij(s), dt = dij(t);
	vector<vector<int>> gs(n), gt(n);
	for (int i = 0; i < n; ++i)
	{
		for (auto p : g[i])
		{
			auto x = p.first;
			auto y = p.second;
			if (ds[i] + y == ds[x])
				gs[i].push_back(x);
			if (dt[i] + y == dt[x])
				gt[i].push_back(x);
		}
	}
	auto cnts = cntways(ds, gs, s), cntt = cntways(dt, gt, t);
	nagai len = ds[t];
	nagai cntall = cnts[t] * cnts[t] % mod;
	for (int i = 0; i < n; ++i)
	{
		if (ds[i] + dt[i] != len)
			continue;
		if (ds[i] == dt[i])
		{
			cntall -= cnts[i] * cnts[i] % mod * cntt[i] % mod * cntt[i] % mod;
			if (cntall < 0)
				cntall += mod;
		}
		for (int j : gs[i])
		{
			if (ds[j] + dt[j] != len)
				continue;
			if (dt[j] + (ds[j] - ds[i]) != dt[i])
				continue;
			if (intersects(ds[i], ds[j], dt[j], dt[i]))
			{
				cntall -= cnts[i] * cnts[i] % mod * cntt[j] % mod * cntt[j] % mod;
				if (cntall < 0)
					cntall += mod;
			}
		}
	}
	cout << cntall << endl;
}
