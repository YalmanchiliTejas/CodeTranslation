#include <bits/stdc++.h>
using namespace std;
#ifdef grief
#define IOS
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) =",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<'\n';}
template<typename I,typename ...T> void _DO(I&&x,T&&...tail){cerr<<x<<" , ";_DO(tail...);}
#else
#define debug(...)
#define IOS do{ios_base::sync_with_stdio(0); cin.tie(0);}while(0);
#endif
typedef long long ll;
typedef pair<ll,ll> pll;

typedef priority_queue<pll,vector<pll>,greater<pll> > heap;
const ll MAX=1e5+5;
const ll INF=4e18;
const ll MOD=1e9+7;
#define eb emplace_back
#define SZ(x) (int)x.size()
#define F first
#define S second
ll n,m,s,t;
vector<pll> adj[MAX];
ll cna[MAX],cnb[MAX];
ll disa[MAX],disb[MAX];
ll add(ll &a,ll b){
	a=(a+b)%MOD;
}
void sp(int st,ll dis[],ll cnt[]){
	for(int i=1;i<=n;i++)	dis[i]=INF;
	cnt[st]=1;
	dis[st]=0;
	heap pq; while(SZ(pq))	pq.pop();
	pq.push({0,st});
	while(SZ(pq)){
		ll now,d;
		tie(d,now)=pq.top();
		pq.pop();
		if(d>dis[now])	continue;
		debug(now);
		assert(d==dis[now]);
		for(auto ii:adj[now]){
			ll dd=d+ii.S;
			int nxt=ii.F;
			if(dd<dis[nxt]){
				dis[nxt]=dd;
				cnt[nxt]=cnt[now];
				pq.push({dd,nxt});
			}
			else if(dd==dis[nxt])
				add(cnt[nxt],cnt[now]);
		}
	}
}
int main(){
	IOS
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v;	cin>>u>>v;
		ll d;		cin>>d;
		adj[u].eb(v,d);
		adj[v].eb(u,d);
	}
	sp(s,disa,cna);
	ll rrd=disa[t];
	sp(t,disb,cnb);
	assert(cna[t]==cnb[s]);
	ll all=cna[t];
	debug(cna[t],cnb[s]);
//	if(!SZ(op)&&!SZ(opa)){
//		cout<<all*all%MOD<< '\n';
//		return 0;
//	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(disa[i]+disb[i]==rrd&&disa[i]==disb[i]){
			ll x=cna[i]*cnb[i]%MOD;
			add(ans,x*(all-x+MOD)%MOD);
		}
		for(auto ii:adj[i]){
			int nxt=ii.F;
			ll d=ii.S;
			if(disa[i]*2<rrd&&disb[nxt]*2<rrd&&disa[i]+disb[nxt]+d==rrd){
				ll x=cna[i]*cnb[nxt]%MOD;
				add(ans,x*(all-x+MOD)%MOD);
			}
		}
	}
	cout<<ans<< '\n';
}
