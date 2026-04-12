/*
     Contest  :
     Task    :
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define pb  push_back
#define mp  make_pair
#define ll  long long
#define int long long
#define F_  first
#define S_  second
#define itr ::iterator 
 
typedef pair<int,int> pii;
 
const int MAX=3e5+99;
const int mod=1e9+7;
const int INF=1e16;
 
vector<pii> vec[MAX];
 
int N,M,S,T,X,Y,Z,dp[MAX][2],dis[MAX][2];
 
void dijkstra(int node,int K)
{
	pair<int,int> cur;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int A=1;A<=N;A++)
	dis[A][K]=INF,dp[A][K]=0;
	dp[node][K]=1;
	dis[node][K]=0;
	pq.push(mp(0,node));
	while(! pq.empty())
	{
		cur=pq.top();
		pq.pop();
		if(cur.first > dis[cur.second][K])
		continue;
		for(auto A:vec[cur.second])
		{
			if(cur.first+A.second < dis[A.first][K])
			{
				dis[A.first][K]=cur.first+A.second;
				dp[A.first][K]=dp[cur.second][K];
				pq.push(mp(dis[A.first][K],A.first));
			}
			else if(cur.first+A.second == dis[A.first][K])
{
			dp[A.first][K]+=dp[cur.second][K];
			dp[A.first][K]%=mod;
}
		}
	}
	return ;
}
 
int solve()
{
	int D,cnt=0;
	dijkstra(S,0);
	dijkstra(T,1);
	D=dis[T][0];
	for(int A=1;A<=N;A++)
	if(dis[A][0]==dis[A][1] and dis[A][0]+dis[A][1]==D)
	{
		cnt+=(((dp[A][0]*dp[A][1])%mod) * ((dp[A][0]*dp[A][1])%mod))%mod;
		cnt%=mod;
	}
	for(int A=1;A<=N;A++)
	for(auto B:vec[A])
	if(dis[A][0]<D/2+D%2 and dis[B.first][1]<D/2+D%2 and dis[A][0]+B.second+dis[B.first][1]==D)
	{
		cnt+=(((dp[A][0]*dp[B.first][1])%mod)* ((dp[A][0]*dp[B.first][1])%mod))%mod;
		cnt%=mod;
	}
	cnt=(dp[T][0]*dp[S][1])%mod-cnt;
	cnt%=mod;
	while(cnt<0)
	cnt+=mod;
	return cnt;
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	/*cin.tie(0);
	cout.tie(0);*/
	
	cin>>N>>M;
	cin>>S>>T;
	for(int A=1;A<=M;A++)
	{
		cin>>X>>Y>>Z;
		vec[X].pb(mp(Y,Z));
		vec[Y].pb(mp(X,Z));
	}
	cout<<solve();
    return 0;
}