/*
   _  __  U _____ u  _  __    
  |"|/ /  \| ___"|/ |"|/ /    
  | ' /    |  _|"   | ' /     
U/| . \\u  | |___ U/| . \\u   
  |_|\_\   |_____|  |_|\_\    
,-,>> \\,-.<<   >>,-,>> \\,-. 
 \.)   (_/(__) (__)\.)   (_/  
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
bool g[17][17];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u][v] = g[v][u] = true;
	}
	vector<int> p;
	int fc = 1;
	for (int i = 1; i <= n; i++)
	{
		fc *= i;
		p.push_back(i);
	}
	int res = 0;
	for (int i = 1; i <= fc; i++)
	{
		if (p[0] != 1) continue;
		bool ok = true;
		for (int j = 1; j < (int)p.size(); j++)
		{
			if (!g[p[j - 1]][p[j]]) ok = false;
		}
		if (ok) res++;
		next_permutation(p.begin(), p.end());
	}
	cout << res << endl;
}

