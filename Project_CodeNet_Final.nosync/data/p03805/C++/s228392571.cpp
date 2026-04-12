#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

ll ans=0;
ll n,m;

void dfs(Graph &G,ll now,vector<bool> &visit){
	bool stop=true;
	
	for(auto next:G[now]){
		if(visit[next]) continue;
		stop=false;

		visit[next]=true;
		dfs(G,next,visit);
		visit[next]=false;
	}

	if(stop){
		bool allpath=true;
		rep(i,n){
			if(!visit[i]){//行っていない頂点があるなら条件を満たさない
				allpath=false;
				break;
			}
		}
		if(allpath) ans++;
	}

	return;
}

int main(){
	cin>>n>>m;
	Graph G(n);
	rep(i,m){
		ll a,b;cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<bool> visit(n,false);
	visit[0]=true;
	dfs(G,0,visit);

	cout<<ans<<endl;
	return 0;
}