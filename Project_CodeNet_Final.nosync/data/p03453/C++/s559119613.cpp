//ΔARC090C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111*2;
const int M = 222222*2;
const int mod = 1e9+7;
const LL INF = (LL)1e18;
struct edge{
	int to;
	LL dis;
	int pr;
}e[M<<1];
int tot=1,la[N];
void clr(){
	tot=1;
	memset(la,0,sizeof(la));
}
void adde(int x,int y,int z){
	tot++;
	e[tot].to=y;
	e[tot].dis=z;
	e[tot].pr=la[x];
	la[x]=tot;
}
int n;
LL dd,ds[N],dt[N];
bool h[N];
int m,x[M],y[M];
LL z[M],f[M];
bool r[M];
int s,t;
pair<LL,int> p[N];
int dp1[N],dp2[N];
vector<int> c;
priority_queue<pair<LL,int> > Q;
LL d[N];
void dijk(int w){
	int i,x,y;
	LL l,z;
	for(i=0;i<N;i=i+1)
		d[i]=INF;
	d[w]=0;
	Q.push(make_pair(-d[w],w));
	while(!Q.empty()){
		x=Q.top().second;
		l=Q.top().first;
		Q.pop();
		if(d[x]!=-l)
			continue;
		for(i=la[x];i;i=e[i].pr){
			y=e[i].to;
			z=e[i].dis;
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				Q.push(make_pair(-d[y],y));
			}
		}
	}
}
int main()
{
	int i,j,xx,yy;
	LL zz,ans,ss;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%lld",&xx,&yy,&zz);
		x[i]=xx,y[i]=yy,z[i]=zz;
		adde(xx,yy,zz);
		adde(yy,xx,zz);
	}
	dijk(s);
	for(i=1;i<=n;i=i+1)
		ds[i]=d[i];
	dijk(t);
	for(i=1;i<=n;i=i+1)
		dt[i]=d[i];
	dd=ds[t];
	for(i=1;i<=n;i=i+1)
		if(ds[i]+dt[i]==dd&&ds[i]==dt[i])
			h[i]=1;
	for(i=1;i<=m;i=i+1){
		xx=x[i],yy=y[i],zz=z[i];
		if(h[xx]|h[yy])
			continue;
		for(j=0;j<=1;j=j+1){
			if(ds[xx]+dt[yy]+zz==dd)
				if(ds[xx]+zz>dt[yy]&&ds[xx]<dt[yy]+zz)
					r[i]=1;
			swap(xx,yy);
		}
	}
	for(i=1;i<=n;i=i+1)
		p[i]=make_pair(ds[i],i);
	sort(p+1,p+n+1);
	dp1[s]=1;
	for(j=1;j<=n;j=j+1){
		xx=p[j].second;
		for(i=la[xx];i;i=e[i].pr){
			yy=e[i].to;
			zz=e[i].dis;
			if(ds[xx]+dt[yy]+zz==dd){
				f[i>>1]=dp1[xx];
				dp1[yy]=(dp1[yy]+dp1[xx])%mod;
			}
		}
	}
	for(i=1;i<=n;i=i+1)
		p[i]=make_pair(dt[i],i);
	sort(p+1,p+n+1);
	dp2[t]=1;
	for(j=1;j<=n;j=j+1){
		xx=p[j].second;
		if(h[xx])
			c.push_back((LL)dp1[xx]*dp2[xx]%mod);
		for(i=la[xx];i;i=e[i].pr){
			yy=e[i].to;
			zz=e[i].dis;
			if(dt[xx]+ds[yy]+zz==dd){
				if(r[i>>1])
					c.push_back((LL)f[i>>1]*dp2[xx]%mod);
				dp2[yy]=(dp2[yy]+dp2[xx])%mod;
			}
		}
	}
	ans=0,ss=0;
	i=c.size();
	while(i--){
		j=c[i];
		ss=(ss+j)%mod;
		ans+=(LL)j*j%mod;
		ans%=mod;
	}
	ans=mod-ans+(LL)ss*ss%mod;
	printf("%d",ans%mod);
	return 0;
}