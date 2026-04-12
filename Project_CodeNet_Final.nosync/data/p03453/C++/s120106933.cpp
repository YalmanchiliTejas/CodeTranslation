#include <bits/stdc++.h>
#define INF 100000000000000007LL
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int n,m;

int u[1000001],v[1000001];
ll d[1000001];

ll dist[2][1000001];
ll cnt[2][1000001];
vector<P> G[1000001];

void dijk(int s,int t,int di){
	for(int i=0;i<n;i++){
		dist[di][i]=INF;
	}
	dist[di][s]=0;
	cnt[di][s]=1;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,s));
	while(que.size()){
		P p=que.top();
		que.pop();
		int v=p.second;
		ll c=p.first;
		if(dist[di][v]<c)continue;
		for(int i=0;i<G[v].size();i++){
			if(dist[di][G[v][i].first]>c+G[v][i].second){
				dist[di][G[v][i].first]=c+G[v][i].second;
				cnt[di][G[v][i].first]=cnt[di][v];
				que.push(P(dist[di][G[v][i].first],G[v][i].first));
			}else if(dist[di][G[v][i].first]==c+G[v][i].second){
				cnt[di][G[v][i].first]=(cnt[di][G[v][i].first]+cnt[di][v])%MOD;
			}
		}
	}
}

int main(void){
	int s,t;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	s--;
	t--;
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&u[i],&v[i],&d[i]);
		u[i]--;
		v[i]--;
		G[u[i]].push_back(P(v[i],d[i]));
		G[v[i]].push_back(P(u[i],d[i]));
	}
	dijk(s,t,0);
	dijk(t,s,1);
	ll ans=cnt[0][t]*(cnt[1][s])%MOD;
	//printf("%lld\n",ans);
	for(int i=0;i<n;i++){
		if((dist[0][i]+dist[1][i])==dist[0][t]){
			if(dist[0][i]==dist[1][i]){
				ll gi=cnt[0][i]*cnt[1][i]%MOD;
				ans-=gi*gi%MOD;
				ans+=MOD;
				ans%=MOD;
			}
		}
	}
	//printf("%lld\n",ans);
	for(int i=0;i<m;i++){
		if((dist[0][u[i]]+dist[1][v[i]]+d[i])==dist[0][t]){
			ll dif=dist[0][u[i]]-dist[1][v[i]];
			ll gi=dist[0][v[i]]-dist[0][u[i]];
			ll gi2=dist[1][u[i]]-dist[1][v[i]];
			gi=max(gi,-gi);
			gi2=max(gi2,-gi2);
			if(dif<0LL)dif=-dif;
			if(dif==d[i])continue;
			if(gi!=d[i] || gi2!=d[i])continue;
			if(dist[0][u[i]]<=dist[1][v[i]] && dist[1][v[i]]<=dist[0][v[i]]){
				ll gi=cnt[0][u[i]]*cnt[1][v[i]]%MOD;
				ans-=(gi*gi)%MOD;
				ans+=MOD;
				ans%=MOD;
			}else if(dist[1][v[i]]<=dist[0][u[i]] && dist[0][u[i]]<=dist[1][u[i]]){
				ll gi=cnt[0][u[i]]*cnt[1][v[i]]%MOD;
				ans-=(gi*gi)%MOD;
				ans+=MOD;
				ans%=MOD;
			}
		}
		swap(u[i],v[i]);
		if((dist[0][u[i]]+dist[1][v[i]]+d[i])==dist[0][t]){
			ll dif=dist[0][u[i]]-dist[1][v[i]];
			ll gi=dist[0][v[i]]-dist[0][u[i]];
			ll gi2=dist[1][u[i]]-dist[1][v[i]];
			if(dif<0LL)dif=-dif;
			if(dif==d[i])continue;
			gi=max(gi,-gi);
			gi2=max(gi2,-gi2);
			if(gi!=d[i] || gi2!=d[i])continue;
			if(dist[0][u[i]]<=dist[1][v[i]] && dist[1][v[i]]<=dist[0][v[i]]){
				ll gi=cnt[0][u[i]]*cnt[1][v[i]]%MOD;
				ans-=(gi*gi)%MOD;
				ans+=MOD;
				ans%=MOD;
			}else if(dist[1][v[i]]<=dist[0][u[i]] && dist[0][u[i]]<=dist[1][u[i]]){
				ll gi=cnt[0][u[i]]*cnt[1][v[i]]%MOD;
				ans-=(gi*gi)%MOD;
				ans+=MOD;
				ans%=MOD;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}