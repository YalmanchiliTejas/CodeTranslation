#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

struct treap
{
	struct node
	{
		node *ch[2];
		ll key, lazy, m;
		int prio, sz;

		node(ll key) : key(key), m(key)
		{
			ch[0] = ch[1] = NULL;
			lazy = 0;
			sz = 1;
			prio = rand();
		}
	}*root;

	node* new_node(ll key)
	{
		return new node(key);
	}

	int size(node *u)
	{
		return u ? u->sz : 0;
	}

	ll getM(node *u)
	{
		return u ? u->m : numeric_limits<ll>::max();
	}

	void push(node *u)
	{
		if(!u)
			return;

		if (u->lazy != 0)
		{
			u->key += u->lazy;
			u->m += u->lazy;
			for (int i = 0; i < 2; ++i)
				if (u->ch[i])
					u->ch[i]->lazy += u->lazy;
			u->lazy = 0;
		}
	}

	node* update(node *u)
	{
		if (u)
		{
			u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
			push(u), push(u->ch[0]), push(u->ch[1]);
			u->m = min({ u->key, getM(u->ch[0]), getM(u->ch[1]) });
		}
		return u;
	}

	pair<node*, node*> split(node* u, int k)
	{// split for the kth first elements
		push(u);

		if (!u)
			return { u, u };

		if (size(u->ch[0]) >= k)
		{
			auto s = split(u->ch[0], k);
			u->ch[0] = s.second;
			return { s.first, update(u) };
		}

		auto s = split(u->ch[1], k - size(u->ch[0]) - 1);
		u->ch[1] = s.first;
		return { update(u), s.second };
	}

	node* merge(node *u, node *v)
	{
		push(u), push(v);

		if (!u || !v)
			return u ? u : v;

		if (u->prio > v->prio)
		{
			u->ch[1] = merge(u->ch[1], v);
			return update(u);
		}

		v->ch[0] = merge(u, v->ch[0]);
		return update(v);
	}

	treap() : root(NULL) {}
};

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	srand(time(0));
	int n, m;
	cin >> n >> m;

	ll ans = 0;
	vector<vector<pair<int, int>>> c(n+1);
	for (int i = 0, a, b, w; i < m; ++i)
	{
		cin >> a >> b >> w;
		c[b].push_back({ a, w });
		ans += w;
	}

	treap t;
	t.root = t.merge(t.root, t.new_node(0));

	for (int i = 1; i <= n; ++i)
	{
		t.root = t.merge(t.new_node(t.root->m), t.root);

		for (auto k : c[i])
		{
			auto p = t.split(t.root, i-k.F+1);
			p.S->lazy += k.S;
			t.root = t.merge(p.F, p.S);
		}
	}

	cout << ans-t.root->m << "\n";

	return 0;
}

