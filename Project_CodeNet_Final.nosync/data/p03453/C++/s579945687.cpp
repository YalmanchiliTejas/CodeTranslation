#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;

vector<P>E[100000];
ll d1[100000],d2[100000];
P p1[100000],p2[100000];
int u[200000],v[200000],d[200000];
ll dp1[100000],dp2[100000];

signed main(){
	int n,m,s,t;scanf("%d%d%d%d",&n,&m,&s,&t);s--;t--;
	rep(i,m){
		scanf("%d%d%d",&u[i],&v[i],&d[i]);u[i]--;v[i]--;
		E[u[i]].push_back(P(d[i],v[i]));
		E[v[i]].push_back(P(d[i],u[i]));
	}
	
	priority_queue<P,vector<P>,greater<P>>que;
	memset(d1,0x3f,sizeof(d1));
	d1[s]=0;que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		if(d1[p.second]!=p.first)continue;
		for(auto u:E[p.second]){
			if(d1[u.second]>p.first+u.first){
				d1[u.second]=p.first+u.first;
				que.push(P(d1[u.second],u.second));
			}
		}
	}
	
	memset(d2,0x3f,sizeof(d2));
	d2[t]=0;que.push(P(0,t));
	while(!que.empty()){
		P p=que.top();que.pop();
		if(d2[p.second]!=p.first)continue;
		for(auto u:E[p.second]){
			if(d2[u.second]>p.first+u.first){
				d2[u.second]=p.first+u.first;
				que.push(P(d2[u.second],u.second));
			}
		}
	}
	
	rep(i,n){
		p1[i].first=d1[i];
		p1[i].second=i;
	}
	rep(i,n){
		p2[i].first=d2[i];
		p2[i].second=i;
	}
	
	sort(p1,p1+n);
	sort(p2,p2+n);
	
	dp1[s]=1;
	rep(i,n){
		for(auto u:E[p1[i].second]){
			if(d1[u.second]==p1[i].first+u.first){
				(dp1[u.second]+=dp1[p1[i].second])%=MOD;
			}
		}
	}
	
	dp2[t]=1;
	rep(i,n){
		for(auto u:E[p2[i].second]){
			if(d2[u.second]==p2[i].first+u.first){
				(dp2[u.second]+=dp2[p2[i].second])%=MOD;
			}
		}
	}
	
	ll ans=dp1[t]*dp1[t];
	
	rep(i,n){//頂点で重なる
		if(d1[i]+d2[i]!=d1[t])continue;
		if(d1[i]==d2[i]){
			ans=(ans+MOD-(dp1[i]*dp1[i]%MOD*dp2[i]%MOD*dp2[i])%MOD)%MOD;
		}
	}
	rep(i,m){//辺(頂点を除く)で重なる
		if(d1[u[i]]>d1[v[i]])swap(u[i],v[i]);
		if(d1[u[i]]+d[i]!=d1[v[i]])continue;
		if(d1[u[i]]+d2[v[i]]+d[i]!=d1[t])continue;
		ll L1=d1[u[i]]+1,R1=d1[u[i]]+d[i]-1;
		ll L2=d2[v[i]]+1,R2=d2[v[i]]+d[i]-1;
		if(!(R2<L1||R1<L2)){
			ans=(ans+MOD-(dp1[u[i]]*dp1[u[i]]%MOD*dp2[v[i]]%MOD*dp2[v[i]])%MOD)%MOD;
		}
	}
	
	cout<<ans<<endl;
}