#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = 1e15;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "03"
const int mxN = 1e5+5;
int n,m,ss,t;
vii G[mxN];
int cnt1[mxN], cnt2[mxN];
int dist1[mxN], dist2[mxN];
bool visited[mxN];
int Pow(int val)
{
	return val*val%mod;
}
void djikstra(int s, int* dist, int* cnt)
{
	priority_queue<pii,vii,greater<pii>> pq;
	pq.push(mp(0,s));
	for(int i=0;i<=n;i++)
	{
		dist[i]=mx;
		visited[i]=false;
	}
	cnt[s]=1;
	dist[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().se;
		int d=pq.top().fi;
		pq.pop();
		if(visited[u] or d!=dist[u])
			continue;
		visited[u]=true;
		for(auto v:G[u])
		{
			if(!visited[v.fi] and dist[v.fi]>dist[u]+v.se)
			{
				cnt[v.fi]=cnt[u];
				dist[v.fi]=dist[u]+v.se;
				pq.push(mp(dist[v.fi],v.fi));
			}
			else if(dist[v.fi]==dist[u]+v.se)
			{
				cnt[v.fi]+=cnt[u];
				cnt[v.fi]%=mod;
			}
		}
	}
}
signed main()
{
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
//    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>ss>>t;
    for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].eb(v,w);
		G[v].eb(u,w);
	}
//	cout<<"here";
	djikstra(ss,dist1,cnt1);
	djikstra(t,dist2,cnt2);
//	cout<<"here";
//	cout<<cnt1[t]<<" "<<cnt2[s]<<endl;
	int Dist=dist1[t], ans=cnt1[t]*cnt2[ss]%mod;
	if(Dist%2==0)
		for(int i=1;i<=n;i++)
			if(dist1[i]*2==Dist and dist1[i]+dist2[i]==Dist)
				ans = (ans-Pow(cnt1[i]*cnt2[i]%mod)%mod+mod)%mod;
	for(int u=1;u<=n;u++)
		for(auto v:G[u])
			if(dist1[u]+dist2[v.fi]+v.se==Dist and dist1[u]*2<Dist and dist2[v.fi]*2<Dist)
//				cout<<u<<" "<<v.fi<<endl;
				ans = (ans-Pow(cnt1[u]*cnt2[v.fi]%mod)%mod+mod)%mod;
	while(ans<0) ans+=mod;
	cout<<ans%mod;
}
