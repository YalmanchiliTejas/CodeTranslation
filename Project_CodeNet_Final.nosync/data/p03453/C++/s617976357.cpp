#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vi lnum;
typedef long double ld;

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979
#define fopen freopen("input.txt", "r", stdin); freopen("output.txt","w", stdout)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define REPR(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define f first
#define s second

const int MOD9 = 1e9 + 7;
const int MOD91 = 1e9 + 9;
const ll MOD12 = 1e12 + 39LL;
const ll MOD15 = 1e15 + 37LL;
const ll INF = 1000LL * 1000* 1000 + 7;
const ll LINF = INF * INF;
const int base = 330;
const int MAXN = 2e5 + 6;
const double EPS = 1e-12;

using namespace std;
int Sum = 0;
const ll mod = 1000 * 1000 * 1000 + 7;

int n , m , s , t;
ll dist1[100000] , dist2[100000];
ll ways1[100000] , ways2[100000];
vector<vector<pair<int , int> > > g(100000);
int mul(int a , int b)
{
	return ((ll)a * b) % mod;
}
int sub(int a , int b)
{
	a -= b;
	if(a < 0)
		a += mod;
	return a;
}
int add(int a , int b)
{
	return a + b >= mod ? a + b - mod : a + b;
}
int main()
{
	//freopen("input.txt" , "r" , stdin);
	scanf("%d %d" , &n , &m);
	scanf("%d %d" , &s , &t);
	s--;t--;
	for(int i = 0; i < m; i++)
	{
		int u , v , d;
		scanf("%d %d %d" , &u , &v , &d);
		u--;v--;
		g[u].pb({v , d});
		g[v].pb({u , d});
	}

	for(int i = 0; i < n; i++)
		dist1[i] = LINF;
	for(int i = 0; i < n; i++)
		dist2[i] = LINF;
	dist1[s] = 0;
	ways1[s] = 1;
	priority_queue < pair<ll,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		ll v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > dist1[v])  continue;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (dist1[v] + len < dist1[to]) {
				dist1[to] = dist1[v] + len;
				ways1[to] = ways1[v];

				q.push (make_pair (-dist1[to], to));
			}
			else if(dist1[v] + len == dist1[to])
			{
				ways1[to] = add(ways1[to] , ways1[v]);
			}
		}
	}
	//cout << dist1[t] << " " << ways1[t] << endl;
	dist2[t] = 0;
	ways2[t] = 1;
	q.push (make_pair (0, t));
	while (!q.empty()) {
		ll v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > dist2[v])  continue;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (dist2[v] + len < dist2[to]) {
				dist2[to] = dist2[v] + len;
				ways2[to] = ways2[v];

				q.push (make_pair (-dist2[to], to));
			}
			else if(dist2[v] + len == dist2[to])
			{
				ways2[to] = add(ways2[to] , ways2[v]);
			}
		}
	}

	ll ans = mul(ways1[t] , ways1[t]);
	ll finishDist = dist1[t];

	bool nt = !(finishDist % 2);
	for(int i = 0; i < n; i++)
	{
		if(dist2[i] == finishDist / 2 && dist1[i] == finishDist / 2 && nt)
		{
			ans = sub(ans , mul(mul(ways1[i] , ways1[i]) , mul(ways2[i] , ways2[i])));
		}
		for(int j = 0; j < g[i].size(); j++)
		{
			int v = g[i][j].first , d = g[i][j].second;
			if(dist1[i] + dist2[v] + d == finishDist && (dist1[i] + d) * 2 > finishDist && (dist2[v] + d) * 2 > finishDist
					&& (dist1[i] + d) * 2 > finishDist && (dist2[v] + d) * 2 > finishDist)
				ans = sub(ans , mul(mul(ways1[i] , ways1[i]) , mul(ways2[v] , ways2[v])));
		}
	}
	cout << ans;
	//freopen("input.txt" , "r" , stdin);

	//system("pause");
}





