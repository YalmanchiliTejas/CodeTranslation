#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 300003
#define pc(x) putchar_unlocked(x);
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
long long n,m,s,t,u,v,w,dist1[mx],dist2[mx],dp1[mx],dp2[mx];
vector<pair<long long,long long>>g[mx];
set<pair<int,int>>ini;
int main(){
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	priority_queue<pair<long long,int>>q;
	q.push({0,s});
	for(int i=1;i<=n;i++)dist1[i]=dist2[i]=1e18;
	dist1[s]=0;
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		for(auto i:g[now.s]){
			long long nxt=-now.f+i.s;
			if(dist1[i.f]>nxt){
				dist1[i.f]=nxt;
				q.push({-nxt,i.f});
			}
		}
	}
	q.push({0,t});
	dist2[t]=0;
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		for(auto i:g[now.s]){
			long long nxt=-now.f+i.s;
			if(dist2[i.f]>nxt){
				dist2[i.f]=nxt;
				q.push({-nxt,i.f});
			}
		}
	}
	for(int i=1;i<=n;i++)q.push({-dist1[i],i});
	dp1[s]=1;
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		//cout<<"ini ";
		//debug(now.s);
		for(auto i:g[now.s]){
			if(dist1[i.f]==-now.f+i.s){
				//debug(now.s);
				//debug(i.f);
				dp1[i.f]=(dp1[i.f]+dp1[now.s])%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++)q.push({-dist2[i],i});
	dp2[t]=1;
	while(!q.empty()){
		auto now=q.top();
		q.pop();
	//	cout<<"ini ";
	//	debug(now.s);
		for(auto i:g[now.s]){
			if(dist2[i.f]==-now.f+i.s){
				//debug(now.s);
				//debug(i.f);
			//	debug(now.s);
			//	debug(i.f);
				dp2[i.f]=(dp2[i.f]+dp2[now.s])%MOD;
			}
		}
	}
	long long node=0,edge=0;
	for(int i=1;i<=n;i++){
		if(dist1[i]==dist2[i] && dist1[i]+dist2[i]==dist1[t]){
			long long sem=(dp1[i]*dp2[i])%MOD;
			node=(node+(sem*sem)%MOD)%MOD;
		}
	}
	for(long long i=1;i<=n;i++){
		for(auto j:g[i]){
			if(dist1[i]+j.s+dist2[j.f]==dist1[t] && dist1[i]*2<dist1[t] && dist2[j.f]*2<dist1[t]){
				long long sem=(dp1[i]*dp2[j.f])%MOD;
				edge=(edge+(sem*sem)%MOD)%MOD;
			}
		}
	}
	long long jaw=(dp1[t]*dp2[s])%MOD;
//	debug(dp1[t]);
//	debug(dp2[s]);
//	debug(node);
//	debug(edge);
	jaw-=node;
	jaw%=MOD;
	if(jaw<0)jaw+=MOD;
	jaw-=edge;
	jaw%=MOD;
	if(jaw<0)jaw+=MOD;
	cout<<jaw<<endl;
}


