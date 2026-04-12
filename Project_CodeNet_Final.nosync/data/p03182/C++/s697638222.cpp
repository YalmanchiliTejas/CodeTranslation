#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct node
{
	int size = 1;
	ll val;
	ll lazy;
};

struct tree
{
	vector<node> t;
	int size = 1;

	tree(int n)
	{
		while(size < n)
			size *= 2;
		t.resize(size * 2);
		for(int i = size - 1; i >= 1; i--)
			t[i].size = t[i * 2].size * 2;
	}

	void propagate(int v)
	{
		for(int x = v * 2; x <= v * 2 + 1; x++)
		{
			t[x].val += t[v].lazy;
			t[x].lazy += t[v].lazy;
		}

		t[v].lazy = 0;
	}

	void update(int v)
	{
		t[v].val = max(t[v * 2].val, t[v * 2 + 1].val);
	}

	void add(int l, int r, ll val, int v = 1)
	{
		if(l == 0 && r == t[v].size - 1)
		{
			t[v].val += val;
			t[v].lazy += val;
			return;
		}

		propagate(v);

		int m = t[v].size / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else 
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		update(v);
	}

	ll get(int l, int r, int v = 1)
	{
		if(l == 0 && r == t[v].size - 1)
			return t[v].val;

		propagate(v);

		int m = t[v].size / 2;
		if(r < m)
			return get(l, r, v * 2);
		else if(m <= l)
			return get(l - m, r - m, v * 2 + 1);
		else
			return max(get(l, m - 1, v * 2), get(0, r - m, v * 2 + 1));
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v(m);
	vector<vector<int>> beg(n + 1), end(n + 1);
	for(int i = 0; i < m; i++)
	{
		int l, r, a;
		cin >> l >> r >> a;
		beg[l].emplace_back(i);
		end[r].emplace_back(i);
		v[i] = {l - 1, a};
	}

	tree tree(n + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int id : beg[i])
			tree.add(0, v[id].first, v[id].second);

		ll ans = tree.get(0, i - 1);
		tree.add(i, i, ans);

		for(int id : end[i])
			tree.add(0, v[id].first, -v[id].second);
	}

	cout << tree.get(0, n) << "\n";
}
