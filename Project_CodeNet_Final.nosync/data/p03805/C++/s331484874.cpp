#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define mp make_pair
#define EPS (int)1e-9
#define PI acos(-1)
#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1000000007;


vi visited;
int n;
int ans = 0;

void dfs(int node, vector<vi>&graph, int cnt)
{
	if(visited[node])
		return;

	if(cnt == n)
		ans++;

	visited[node] = true;

	for(int x: graph[node])
	{
		dfs(x, graph, cnt+1);
	}

	visited[node] = false;

	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, x, y;
	cin >> n >> m;

	visited = vi(n+1, false);
	vector<vi> graph(n+1);

	for(int i = 0; i < m; i++)
	{
		cin  >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	dfs(1, graph, 1);
	cout << ans << endl;
	return 0;	
}