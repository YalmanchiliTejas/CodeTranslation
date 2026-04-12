#include <bits/stdc++.h>
 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(vv) vv.begin(), vv.end()
 
using namespace std;
const ll maxn=1e6+100,inf=1e18,LOG=23,mod=1e9 + 7;
 
#define int ll

int n, m, l[maxn], r[maxn], v[maxn], dp[maxn], dpbez[maxn], t[4*maxn], p[4*maxn];
vector <pair <int, int> > vec[maxn];

void push(int v)
{
	if(p[v])
	{
		t[v * 2] += p[v];
		t[v * 2 + 1] += p[v];
		p[v * 2] += p[v];
		p[v * 2 + 1] += p[v];
		p[v] = 0;
	}
}

void upd(int v, int tl, int tr, int l, int r, int cost)
{
	if(l <= tl && tr <= r)
	{
		t[v] += cost;
		p[v] += cost;
		return;
	}
	if(l > tr || r < tl)
	{
		return;
	}
	push(v);
	upd(v * 2, tl, (tl + tr) / 2, l, r, cost);
	upd(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r, cost);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
	if(l <= tl && tr <= r)
	{
		return t[v];
	}
	if(l > tr || r < tl)
	{
		return 1e18;
	}
	push(v);
	return min(get(v * 2, tl, (tl + tr) / 2, l, r), get(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r));
}

main()
{
	IOS
	cin >> n >> m;
	int sum = 0;
	forn(1, i, m)
	{
		cin >> l[i] >> r[i] >> v[i];
		sum += v[i];
		vec[r[i]].pb(mp(l[i], v[i]));
	}
	++n;
	forn(1, i, n)
	{
		/*forn(1, j, n)
		{	
			upd(1, 1, n, j, j, 0);
			cout << get(1, 1, n, j, j) << " ";
		}
		cout << endl;
		*/
		dp[i] = get(1, 1, n, 1, i);
		dpbez[i] = min(dp[i], min(dp[i - 1], dpbez[i - 1]));
		sort(all(vec[i]));
		FOR(0, j, vec[i].size())
		{
			int cost = vec[i][j].s;
			while(j < vec[i].size() - 1 && vec[i][j].f == vec[i][j + 1].f)
			{
				++j;
				cost += vec[i][j].s;
			}
			upd(1, 1, n, 1, vec[i][j].f, cost);
		}
		upd(1, 1, n, i + 1, i + 1, dp[i]);
	}
	cout << sum - get(1, 1, n, 1, n);
}