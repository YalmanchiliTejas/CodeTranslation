#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=4e5+10,maxm=4e5+10,mod=1e9+7;
int n,m,s,t,a[maxm],b[maxm],d[maxm];
ll ans,res,mindis;
bool xxx[maxm];
struct graph1{
	int ecnt,ebeg[maxn],eto[maxm],enxt[maxm],ew[maxm];
	ll dis[maxn];
	bool inq[maxn];
	void ae(int u,int v,int w){
		++ecnt;
		enxt[ecnt]=ebeg[u];
		ebeg[u]=ecnt;
		eto[ecnt]=v;
		ew[ecnt]=w;
	}
	void spfa(int s){
		for(int i=1;i<=n;++i)
			dis[i]=1e18;
		dis[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int pos=q.front();q.pop();
			for(int i=ebeg[pos],v;i;i=enxt[i])
				if(dis[v=eto[i]]>dis[pos]+ew[i]){
					dis[v]=dis[pos]+ew[i];
					if(!inq[v]){
						inq[v]=true;
						q.push(v);
					}
				}
			inq[pos]=false;
		}
	}
}g1,g2;
struct graph2{
	int ecnt,ebeg[maxn],eto[maxm],enxt[maxm],ew[maxm];
	ll dp[maxn];int deg[maxn];
	void ae(int u,int v,int w){
		++ecnt;
		enxt[ecnt]=ebeg[u];
		ebeg[u]=ecnt;
		eto[ecnt]=v;
		ew[ecnt]=w;
		++deg[v];
	}
	void top(int s){
		queue<int> q;
		dp[s]=1;
		q.push(s);
		while(!q.empty()){
			int pos=q.front();q.pop();
			for(int i=ebeg[pos],v;i;i=enxt[i]){
				v=eto[i];
				dp[v]=(dp[v]+dp[pos])%mod;
				--deg[v];
				if(!deg[v])
					q.push(v);
			}
		}
	}
}g3,g4;

int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i],&b[i],&d[i]);
		g1.ae(a[i],b[i],d[i]);
		g1.ae(b[i],a[i],d[i]);
		g2.ae(a[i],b[i],d[i]);
		g2.ae(b[i],a[i],d[i]);
	}
	g1.spfa(s);g2.spfa(t);
//	for(int i=1;i<=n;++i)
//		cout<<g1.dis[i]<<' '<<g2.dis[i]<<endl;
	mindis=g1.dis[t];
//	cout<<mindis<<endl;
	for(int i=1;i<=m;++i){
		if(g1.dis[a[i]]+d[i]+g2.dis[b[i]]==mindis)
			g3.ae(a[i],b[i],d[i]),g4.ae(b[i],a[i],d[i]),xxx[i]=true;
		else if(g1.dis[b[i]]+d[i]+g2.dis[a[i]]==mindis){
			swap(a[i],b[i]);
			g3.ae(a[i],b[i],d[i]),g4.ae(b[i],a[i],d[i]),xxx[i]=true;
		}
	}
	g3.top(s);g4.top(t);
	ans=g3.dp[t]*g3.dp[t]%mod;
	for(int i=1;i<=n;++i)
		if(g1.dis[i]*2==mindis)
			res=(res+g3.dp[i]*g4.dp[i]%mod*g3.dp[i]%mod*g4.dp[i])%mod;
	for(int i=1;i<=m;++i)
		if(xxx[i]&&g1.dis[a[i]]*2<mindis&&g2.dis[b[i]]*2<mindis)
			res=(res+g3.dp[a[i]]*g4.dp[b[i]]%mod*g3.dp[a[i]]%mod*g4.dp[b[i]])%mod;
	printf("%lld\n",(ans-res+mod)%mod);
	return 0;
}