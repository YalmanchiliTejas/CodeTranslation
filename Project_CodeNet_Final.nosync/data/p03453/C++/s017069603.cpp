/*
Author: CNYALI_LK
LANG: C++
PROG: e.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
//template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll beg[102424],to[408888],lst[408888],w[408888],e;
ll diss[102424],dist[102424],cnts[102424],cntt[102424],n,m,ins[102424],rd[102424];
queue<ll> q;
void add(ll u,ll v,ll z){
	to[++e]=v;
	lst[e]=beg[u];
	beg[u]=e;
	w[e]=z;
}
void spfa(ll s,ll *dis){
	for(ll i=1;i<=n;++i){dis[i]=0x3f3f3f3f3f3f3f3f;ins[i]=0;}
//	dis[s]=0;
	while(!q.empty())q.pop();
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		ins[s]=0;
		for(ll i=beg[s];i;i=lst[i]){
			if(chkmin(dis[to[i]],dis[s]+w[i])){
//				debug("")
				if(!ins[to[i]]){
					ins[to[i]]=1;
					q.push(to[i]);
				}
			}
		}
	}
}
const ll p=1000000007;
void dfss(ll x){
	for(ll i=beg[x];i;i=lst[i])if(diss[x]+w[i]==diss[to[i]]){
		cnts[to[i]]+=cnts[x];
		cnts[to[i]]%=p;
		if(!--rd[to[i]])dfss(to[i]);
	}
}
ll sqr(ll a){return a*a%p;}
void dfst(ll x){
	for(ll i=beg[x];i;i=lst[i])if(dist[x]+w[i]==dist[to[i]]){
		cntt[to[i]]+=cntt[x];
		cntt[to[i]]%=p;
		if(!--rd[to[i]])dfst(to[i]);
	}
}

int main(){
#ifdef cnyali_lk
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	ll s,t,u,v,omega;
	n=read();
	m=read();s=read();t=read();	
	for(ll i=1;i<=m;++i){
		u=read();v=read();omega=read();
		add(u,v,omega);
		add(v,u,omega);
	}
	spfa(s,diss);
	for(ll i=1;i<=n;++i)rd[i]=cnts[i]=0;
	for(ll i=1;i<=n;++i)for(ll j=beg[i];j;j=lst[j])if(diss[i]+w[j]==diss[to[j]])++rd[to[j]];
	cnts[s]=1;
	dfss(s);
	spfa(t,dist);
	for(ll i=1;i<=n;++i)rd[i]=cntt[i]=0;
	for(ll i=1;i<=n;++i)for(ll j=beg[i];j;j=lst[j])if(dist[i]+w[j]==dist[to[j]])++rd[to[j]];
	cntt[t]=1;
	dfst(t);
	ll dis=diss[t];
	ll ans=cnts[t]*cnts[t]%p;

/*	for(ll i=1;i<=n;++i)printf("%lld%c",diss[i],i==n?'\n':' ');
	for(ll i=1;i<=n;++i)printf("%lld%c",cnts[i],i==n?'\n':' ');
	for(ll i=1;i<=n;++i)printf("%lld%c",dist[i],i==n?'\n':' ');
	for(ll i=1;i<=n;++i)printf("%lld%c",cntt[i],i==n?'\n':' ');*/
//	printf("%lld\n",ans);
	for(ll i=1;i<=n;++i)if(diss[i]<<1==dis&&diss[i]+dist[i]==dis)ans=(ans-sqr(cnts[i]*cntt[i]%p)+p)%p;
//	printf("%lld\n",ans);
	if(dis&1){
//		while(1);
		for(ll i=1;i<=n;++i)if(diss[i]<dis>>1){
			for(ll j=beg[i];j;j=lst[j]){
				if(diss[to[j]]==diss[i]+w[j]&&dist[i]==dist[to[j]]+w[j]&&diss[i]+dist[to[j]]+w[j]==dis&&dist[to[j]]<(dis>>1))
				ans=(ans-sqr(cnts[i]*cntt[to[j]]%p)+p)%p;
			}
		}
	}
	else{
//		printf("adyyc");
		dis>>=1;
		for(ll i=1;i<=n;++i)if(diss[i]<dis){
			for(ll j=beg[i];j;j=lst[j]){
				if(diss[to[j]]==diss[i]+w[j]&&dist[i]==dist[to[j]]+w[j]&&diss[i]+dist[to[j]]+w[j]==dis+dis&&dist[to[j]]<dis){

					ans=(ans-sqr(cnts[i]*cntt[to[j]]%p)+p)%p;
//					printf("Poll %lld---%lld\n",i,to[j]);
				}
			}
		}

	}
	printf("%lld\n",ans);
	return 0;
}

