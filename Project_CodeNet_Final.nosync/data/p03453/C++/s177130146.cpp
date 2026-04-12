#include "bits/stdc++.h"
 
#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
 
vector<pii> adj[1000005];
void solve(){
	int N,M,S,T;
	cin>>N>>M>>S>>T;
	rep(i,1,M+1){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	vi dp1(N+1),d1(N+1,LLONG_MAX);
	vi dp2(N+1),d2(N+1,LLONG_MAX);
	vi order1,order2;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,S});
	while(!pq.empty()){
		auto cur=pq.top();
		pq.pop();
		if(d1[cur.S]!=LLONG_MAX)continue;
		order1.pb(cur.S);
		d1[cur.S]=cur.F;
		for(auto i:adj[cur.S]){
			pq.push({cur.F+i.S,i.F});
		}
	}
	pq.push({0,T});
	while(!pq.empty()){
		auto cur=pq.top();
		pq.pop();
		if(d2[cur.S]!=LLONG_MAX)continue;
		order2.pb(cur.S);
		d2[cur.S]=cur.F;
		for(auto i:adj[cur.S]){
			pq.push({cur.F+i.S,i.F});
		}
	}
	assert(d1[T]==d2[S]);
	{
		dp1[S]=1;
		for(auto cur:order1){
			for(auto i:adj[cur]){
				if(d1[cur]+i.S==d1[i.F] and d1[cur]+d2[cur]==d1[T] and d1[i.F]+d2[i.F]==d1[T]){
					dp1[i.F]+=dp1[cur];
					if(dp1[i.F]>=hell)dp1[i.F]-=hell;
				}
			}
		}
	}
	{
		dp2[T]=1;
		for(auto cur:order2){
			for(auto i:adj[cur]){
				if(d2[cur]+i.S==d2[i.F] and d1[cur]+d2[cur]==d1[T] and d1[i.F]+d2[i.F]==d1[T]){
					dp2[i.F]+=dp2[cur];
					if(dp2[i.F]>=hell)dp2[i.F]-=hell;
				}
			}
		}
	}
	tr(d1);
	tr(dp1);
	tr(d2);
	tr(dp2);
	assert(dp1[T]==dp2[S]);
	ll ans=1LL*dp1[T]*dp2[S]%hell;
	for(int i=1;i<=N;i++){
		if(d1[i]==d2[i] and d1[i]+d2[i]==d1[T]){
			ans=(ans-1LL*dp1[i]*dp2[i]%hell*dp1[i]%hell*dp2[i]%hell)%hell;
		}
	}
	for(int i=1;i<=N;i++){
		for(auto j:adj[i]){
			if(d1[i]+j.S==d1[j.F] and d1[i]+d2[i]==d1[T] and d1[j.F]+d2[j.F]==d1[T]){
				if(d1[i]*2LL<d1[T] and d1[T]<d1[j.F]*2LL){
					ans=(ans-1LL*dp1[i]*dp2[j.F]%hell*dp1[i]%hell*dp2[j.F]%hell+hell)%hell;
				}
			}
		}
	}
	cout<<ans;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}