#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<pair<ll,ll> > > v(222222);

ll dist[2][222222];
ll dp[2][222222];

void dijkstra(int id,int a)
{
	REP(i,222222)dist[id][i] = INF;
	dist[id][a] = 0;
	dp[id][a] = 1;
	
	priority_queue<P,vector<P>,greater<P> > pq;
	
	pq.push(MP(0,a));
	
	while(!pq.empty())
	{
		P p = pq.top();pq.pop();
		int node = p.SE;
		ll dis = p.FI;
		
		if(dist[id][node] < dis)continue;
		
		REP(i,v[node].size())
		{
			int saki = v[node][i].FI;
			int kyo = v[node][i].SE;
			if(dist[id][saki] > dist[id][node] + kyo)
			{
				dist[id][saki] = dist[id][node] + kyo;
				dp[id][saki] = dp[id][node];
				pq.push(MP(dist[id][saki],saki));
			}
			else if(dist[id][saki] == dist[id][node] + kyo)
			{
				dp[id][saki] = (dp[id][saki] + dp[id][node])%MOD;
			}
		}
	}
}

int main()	
{
	ll n,m;cin >> n >> m;
	ll s,t;cin >> s >> t;
	s--;t--;
	vector<pair<pair<ll,ll>,ll > > edge;
	
	REP(i,m)
	{
		ll a,b,d;cin >> a >> b >> d;
		a--;b--;
		v[b].PB(MP(a,d));
		v[a].PB(MP(b,d));
		edge.PB(MP(MP(a,b),d));
	}
	
	dijkstra(0,s);
	dijkstra(1,t);
	
	/*
	SHOW1d(dist[0],n)
	SHOW1d(dp[0],n)
	SHOW1d(dist[1],n)
	SHOW1d(dp[1],n)
	*/
	
	ll ans = dp[0][t]*dp[1][s]%MOD;
	//cout << "ans is " << ans << endl;
	ll kyo = dist[0][t];
	REP(i,n)
	{
		if(dist[0][i] == dist[1][i] && dist[0][i] + dist[1][i] == kyo)
		{
			ll tmp = (dp[0][i]*dp[0][i]%MOD)*(dp[1][i]*dp[1][i]%MOD)%MOD;
		//	cout << "tmp1 is " << tmp << endl;
			ans = (ans + MOD - tmp)%MOD;
		}
	}
	
	REP(i,m)
	{
		ll a = edge[i].FI.FI;
		ll b = edge[i].FI.SE;
		if(dist[0][a] > dist[0][b])swap(a,b);
		if(dist[0][a] + dist[1][b] + edge[i].SE == kyo)
		{
			ll A = dist[0][a];
			ll B = dist[1][b];
			ll C = dist[0][a] + edge[i].SE;
			ll D = dist[1][b] + edge[i].SE;
			if(max(A,B) < min(C,D))
			{
				ll tmp = (dp[0][a]*dp[0][a]%MOD)*(dp[1][b]*dp[1][b]%MOD)%MOD;
			//	cout << "tmp2 is " << tmp << ' ' << a << ' ' << b << endl;
				ans = (ans + MOD - tmp)%MOD;
			}
		}
	}
		
	cout << ans%MOD << endl;
	
	return 0;
}