#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

int get_sz(vector<vi> &tree, vi &sz, int v)
{
	int res = 1;
	for (auto u : tree[v])
	{
		res += get_sz(tree, sz, u);
	}
	return sz[v] = res;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n; cin >> n;
	vector<vi> g(n);
	REP(i, n - 1)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int r = 0;
	vector<bool> vis(n);
	vis[r] = true;
	vector<set<int>> tree(n);
	queue<int> que;
	que.push(r);
	vi par(n);
	par[r] = -1;
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (auto u : g[v])
		{
			if (vis[u]) continue;
			vis[u] = true;
			tree[v].insert(u);
			par[u] = v;
			que.push(u);
		}
	}
	vi childcnt(n);
	REP(i, n) childcnt[i] = tree[i].size();

	set<int> leaf;
	set<int> uncolor; REP(i, n) uncolor.insert(i);
	vi color(n, -1);
	REP(i, n)
	{
		if (tree[i].empty()) leaf.insert(i);
	}
	bool ans = true;
	//for (auto v : leaf)
	while(!leaf.empty())
	{
		int v = *leaf.begin();
		leaf.erase(v);
		if (v == r)
		{
			color[v] = 0;
		}
		else
		{
			int u = par[v];
			color[v] = 1;
			uncolor.erase(v);
			if (color[u] != -1)
			{
				ans = false;
				break;
			}
			color[u] = 0;
			uncolor.erase(u);

			if (u != r)
			{
				childcnt[par[u]]--;
				if (childcnt[par[u]] == 0)
				{
					leaf.insert(par[u]);
				}
			}
		}
	}

	if (ans)
	{
		REP(i, n)
		{
			assert(color[i] != -1);
		}
		vi color2(n);
		REP(i, n)
		{
			if (color[i] == 1)
			{
				color2[i] = 1;
				for (auto v : g[i]) color2[v] = 1;
			}
		}
		for (auto c : color2)
		{
			if (c == 0) ans = false;
		}
	}
	cout << (ans ? "Second" : "First") << endl;
	return 0;
}