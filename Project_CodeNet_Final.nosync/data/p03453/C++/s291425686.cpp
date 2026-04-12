#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N,M;
int S,T;
vector<P>G[100005];
vector<int>dis1,ans1,dis2,ans2;
void dijkstra(int s,vector<int>&dis,vector<int>&ans){
	dis.resize(N,inf);ans.resize(N,0);
	dis[s]=0;ans[s]=1;
	priority_queue<P,vector<P>,greater<P>>que;
	que.push({0,s});
	while(!que.empty()){
		P p=que.top();que.pop();
		if(dis[p.second]<p.first)continue;
		for(P e:G[p.second]){
			if(dis[e.first]==p.first+e.second){
				ans[e.first]+=ans[p.second];
				ans[e.first]%=mod;
			}else if(dis[e.first]>p.first+e.second){
				dis[e.first]=p.first+e.second;
				ans[e.first]=ans[p.second];
				que.push({dis[e.first],e.first});
			}
		}
	}
}
signed main() {
	cin>>N>>M>>S>>T;S--;T--;
	rep(i,M){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	dijkstra(S,dis1,ans1);
	dijkstra(T,dis2,ans2);
	int ans=ans1[T]*ans2[S]%mod;
	rep(i,N){
		if(dis1[i]+dis2[i]!=dis1[T])continue;
		if(dis1[i]==dis2[i]){
			ans-=ans1[i]*ans1[i]%mod*ans2[i]%mod*ans2[i]%mod;
			ans=(ans+mod)%mod;
			continue;
		}
		for(P e:G[i]){
			if(dis1[i]+e.second+dis2[e.first]!=dis1[T])continue;
			if(dis1[e.first]==dis2[e.first])continue;
			if(dis1[e.first]<dis2[e.first]||dis2[i]<dis1[i])continue;
			ans-=ans1[i]*ans1[i]%mod*ans2[e.first]%mod*ans2[e.first]%mod;
			ans=(ans+mod)%mod;
		}
	}
	cout<<ans<<endl;
}
