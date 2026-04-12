//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)1e5 + 228;

using namespace std;

int n;
vector < int > g[N];

int dfs(int v, int pr)
{
	int cnt = 0;
	for (auto to : g[v])
	{
		if (to == pr)
			continue;
		cnt += dfs(to, v);
	}
	if (cnt > 1)
	{
		cout << "First" << endl;
		exit(0);
	}           
	if (pr == -1 && cnt == 0)
	{
		cout << "First" << endl;
		exit(0);
	}
	return 1 - cnt;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d", &n);
	forn(i, n - 1)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	//~solves
	if (n == 2)
	{	
		cout << "Second" << endl;
		return 0;
	}            
	int root = -1;
	forn(i, n)
	{
		if ((int)g[i].size() > 1)	
		{
			root = i;
			break;
		}
	}
	dfs(root, -1);
	cout << "Second" << endl;

	return 0;
}

