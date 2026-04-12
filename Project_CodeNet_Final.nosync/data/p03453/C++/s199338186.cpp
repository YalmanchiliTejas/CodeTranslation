// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;

const ll inf=1e18;
const int N=1e5+100;
vector<ii>gfo[N];
priority_queue<ii,vector<ii>,greater<ii>>pq;

void dijkstra(int s,vector<ll>&dist){
	For(i,0,sz(dist))dist[i]=inf;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		ii data=pq.top();
		pq.pop();
		int d=data.ff;
		int u=data.ss;
		if(d>dist[u])continue;
		for(ii v:gfo[u]){
			if(dist[u]+v.ss<dist[v.ff]){
				dist[v.ff]=dist[u]+v.ss;
				pq.push({dist[v.ff],v.ff});
			}
		}
	}
}

const int mod=1e9+7;
vector<int>adj[3][N];
vector<ii>ctm[N];
bool vst[N];
ll dp[3][N];
int in[N];

void build(int s,int n,int id){
	memset(in,0,sizeof(in));
	For(i,0,n)for(int v:adj[id][i])in[v]++;
	queue<int>q;	
	q.push(s);
	dp[id][s]=1;
	
	//cout<<"inicio build"<<endl;
	//For(i,0,n)trace(in[i]);
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[id][u]){
			//trace(v);
			in[v]--;
			//trace(in[v]);
			dp[id][v]+=dp[id][u];
			if(dp[id][v]>=mod)dp[id][v]-=mod;
			if(in[v]==0)q.push(v);
		}
	}

	//For(i,0,n)trace(dp[id][i]);

}



int main(){	
	int n,m;cin>>n>>m;
	int s,t;cin>>s>>t;
	s--,t--;
	For(i,0,m){
		int u,v,d;cin>>u>>v>>d;
		u--,v--;
		gfo[u].pb({v,d});
		gfo[v].pb({u,d});
	}
	vector<ll>d1(n),d2(n);
	dijkstra(s,d1);
	dijkstra(t,d2);

	//For(i,0,n)cout<<d1[i]<<" ";
	//cout<<endl;
	//For(i,0,n)cout<<d2[i]<<" ";
	//cout<<endl;

	if(d1[t]==-1){
		cout<<"0"<<endl;
		return 0;
	}
	For(u,0,n)if(d1[u]!=-1){
		for(ii v:gfo[u]){
			if(d1[u]+v.ss==d1[v.ff]){
				if(d1[u]+d2[v.ff]+v.ss!=d1[t])continue;
				adj[0][u].pb(v.ff);
				adj[1][v.ff].pb(u);
				ctm[u].pb(v);
			}
		}
	}

	//For(u,0,n){
	//	trace(u);
	//	for(int v:adj[1][u])cout<<v<<" ";
	//	cout<<endl;
	//}

	memset(vst,false,sizeof(vst));
	build(s,n,0);
	memset(vst,false,sizeof(vst));
	build(t,n,1);
	
	ll ans=dp[0][t];
	ans=(ans*ans)%mod;
	//trace(dp[0][t]);
	//trace(ans);
	For(i,0,n)if(d1[i]+d2[i]==d1[t]){
		if(d1[i]!=d2[i])continue;
		//trace(i);
		ll val=(dp[0][i]*dp[1][i])%mod;
		ans-=(val*val)%mod;
		if(ans<0)ans+=mod;
	}

	//trace(ans);

	For(u,0,n){
		for(ii par:ctm[u]){
			int v=par.ff;
			ll w=par.ss;
			ll dif=abs(d1[u]-d2[v]);
			if(dif<w){
				ll val=(dp[0][u]*dp[1][v])%mod;
				ans-=(val*val)%mod;
				if(ans<0)ans+=mod;
			}
		}
	}


	cout<<ans<<endl;
	
	return 0;
}
