#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

ll dist[10][10];
ll n, m, w, t;
ll shpdp[10][1111];
ll knapdp[555][11111];

ll shp(int v, int used)
{
	if (used == (1 << n) - 1) return dist[v][n];
	if (shpdp[v][used] >= 0) return shpdp[v][used];
	ll res = INF;
	REP(i, n)
	{
		if ((used >> i) & 1) continue;
		chmin(res, shp(i, used | (1 << i)) + dist[v][i]);
	}
	return shpdp[v][used] = res;
}

ll knapsack(int i, int wei, vi& weight, vi& value)
{
	if (i == weight.size()) return 0;
	if (knapdp[i][wei] >= 0) return knapdp[i][wei];
	ll res = 0;
	if (weight[i] == 0) res = knapsack(i + 1, wei, weight, value);
	else
	{
		if (wei >= weight[i])
		{
			chmax(res, knapsack(i, wei - weight[i], weight, value) + value[i]);
			chmax(res, knapsack(i + 1, wei - weight[i], weight, value) + value[i]);
		}
		chmax(res, knapsack(i + 1, wei, weight, value));
	}
	return knapdp[i][wei] = res;
}

int main()
{
	cin.sync_with_stdio(false);
	map<string, pii> mp;
	cin >> n >> m >> w >> t;
	REP(i, m)
	{
		string s; int v, p;
		cin >> s >> v >> p;
		mp[s] = pii(v, p);
	}
	vi x(n), y(n);
	vector<vi> weight(n), value(n);
	REP(i, n)
	{
		int l;
		cin >> l >> x[i] >> y[i];
		REP(j, l)
		{
			string r; int q;
			cin >> r >> q;
			weight[i].push_back(mp[r].first);
			value[i].push_back(mp[r].second - q);
		}
	}
	x.push_back(0), y.push_back(0);
	REP(i, n+1)REP(j, n+1)
	{
		dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
	}
	vi cost(1 << n), val(1<<n);
	REP(i, 1 << n)
	{
		MS(shpdp, -1);
		cost[i] = shp(n, i);
		vi tw, tv;
		REP(j, n)
		{
			if ((i >> j) & 1) continue;
			REP(k, weight[j].size())
			{
				tw.push_back(weight[j][k]);
				tv.push_back(value[j][k]);
			}
		}
		MS(knapdp, -1);
		val[i] = knapsack(0, w, tw, tv);
	}
	MS(knapdp, -1);
	cout << knapsack(0, t, cost, val) << endl;
	return 0;
}