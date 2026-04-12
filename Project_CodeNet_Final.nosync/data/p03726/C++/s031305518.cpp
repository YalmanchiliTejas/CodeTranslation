# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0LL)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define bin(x) cerr<< #x << " : " << bitset<4>(x) << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define MP make_pair
 
const int MAXN = 100 * 1000 + 10;
vector <int> adj[MAXN];
bool b[MAXN];

void dfs(int u, int p)
{
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	if (!b[u])
	{
		if (b[p])
		{
			cout << "First\n";
			exit (0);
		}
		b[p] = b[u] = true;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	b[0] = true;
	dfs(1, 0);
	cout << "Second\n";

	return 0;
}
