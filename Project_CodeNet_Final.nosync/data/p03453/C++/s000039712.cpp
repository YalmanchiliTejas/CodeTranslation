//              _      _                 
//             (_)    | |                
//    _ __ ___  _  ___| |__   __ _  ___  
//   | '_ ` _ \| |/ __| '_ \ / _` |/ _ \ 
//   | | | | | | | (__| | | | (_| | (_) |
//   |_| |_| |_|_|\___|_| |_|\__,_|\___/ 
//                                       
// 
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int inf=1e18+9;
const int MAX=1e5+5;
const int mod=1e9+7;
int dp[MAX][2];
int ile[MAX][2];
vector<pii> P[MAX];
int n,m,s,t,now=0;
int norm(int x)
{
	while (x>=mod)x-=mod;
	return x;
}
void dijkstra(int u)
{
	for (int i=1;i<=n;i++)dp[i][now]=inf;
	dp[u][now]=0;
	ile[u][now]=1;
	priority_queue<pii>Q;
	Q.push(mp(0,u));
	while (!Q.empty())
	{
		pii akt=Q.top();
		Q.pop();
		akt.st=-akt.st;
		if (akt.st!=dp[akt.nd][now])continue;
		for (auto it:P[akt.nd])
		{
			int v=it.st;
			int cost=it.nd;
			if (dp[akt.nd][now]+cost<=dp[v][now])
			{
				if (dp[akt.nd][now]+cost<dp[v][now])ile[v][now]=ile[akt.nd][now],dp[v][now]=dp[akt.nd][now]+cost,Q.push(mp(-dp[v][now],v));
				else ile[v][now]=norm(ile[v][now]+ile[akt.nd][now]);
			}
		}
	}
	now++;
}
vector<pair<pii,int>>edges;
int32_t main()
{
  BOOST;
  cin>>n>>m>>s>>t;
  for (int i=1;i<=m;i++)
  {
  	int a,b,c;
  	cin>>a>>b>>c;
  	P[a].pb(mp(b,c));
  	P[b].pb(mp(a,c));
  	edges.pb(mp(mp(a,b),c));
  	edges.pb(mp(mp(b,a),c));
  }
  dijkstra(s),dijkstra(t);
  int ans=(ile[t][0]*ile[t][0])%mod;
  int stala=dp[t][0];
  for (int i=1;i<=n;i++)
  {
  	if (dp[i][0]*2==stala && dp[i][1]*2==stala)
  	{
  		int x=(ile[i][0]*ile[i][1])%mod;
  		x=(x*x)%mod;
  	  ans=(ans-x+mod)%mod;
  	}
  }
  
  for (auto it:edges)
  {
  	int a=it.st.st;
  	int b=it.st.nd;
  	int c=it.nd;
  	if (dp[a][0]*2<stala && dp[b][1]*2<stala && c+dp[a][0]+dp[b][1]==stala)
  	{
  		int x=(ile[a][0]*ile[b][1])%mod;
  		x=(x*x)%mod;
  	  ans=(ans-x+mod)%mod;
  	}
  }
  cout<<ans;
  return 0;
}
