#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define x first
#define y second

const ll inf=1e18;

//arc090_Problem_E

ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void print(ll x)
{
    if(x<0)putchar('-'),x=-x;
    short a[20]= {},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(ll i=sz-1; i>=0; i--)putchar('0'+a[i]);
}

struct edge{
	ll fr,tt,len;
} ed[4444444];
ll n,m;
ll s,t;
vector<pair<ll,ll> > adj[222222];
ll d1[2222222],d2[2222222];
ll w1[2222222],w2[2222222];
int vis[111111];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
const ll mod=1e9+7;

int main(){
	n=read(),m=read();
	s=read(),t=read();
	for(ll i=1;i<=m;i++){	
		ll fr=read(),tt=read(),len=read();
		adj[fr].pb(mp(tt,len));
		adj[tt].pb(mp(fr,len));
		ed[i]={fr,tt,len};
		ed[i+m]={tt,fr,len};
	}
	
	for(ll i=1;i<=n;i++) d1[i]=d2[i]=inf;
	d1[s]=0;
	w1[s]=1;
	
	q.push(mp(0,s));
	while(!q.empty()){
		pair<ll,ll> nw=q.top();
		q.pop();
		ll u=nw.y;
		if(vis[u]) continue; else vis[u]=1;
		for(ll i=0;i<adj[u].size();i++){
			ll v=adj[u][i].x;
			if(d1[v]>d1[u]+adj[u][i].y){
				d1[v]=d1[u]+adj[u][i].y;
				w1[v]=w1[u];
				q.push(mp(d1[v],v));
			}
			else if(d1[v]==d1[u]+adj[u][i].y){
				w1[v]=(w1[v]+w1[u])%mod;
			}
		}
	}
	
	while(!q.empty()) q.pop();
	d2[t]=0;
	w2[t]=1;
	q.push(mp(0,t));
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		pair<ll,ll> nw=q.top();
		q.pop();
		ll u=nw.y;
		if(vis[u]) continue; else vis[u]=1;
		for(ll i=0;i<adj[u].size();i++){
			ll v=adj[u][i].x;
			if(d2[v]>d2[u]+adj[u][i].y){
				d2[v]=d2[u]+adj[u][i].y;
				w2[v]=w2[u];
				q.push(mp(d2[v],v));
			}
			else if(d2[v]==d2[u]+adj[u][i].y){
				w2[v]=(w2[v]+w2[u])%mod;
			}
		}
	}
	
	ll ans=w1[t]%mod*w1[t]%mod;
	
	for(ll i=1;i<=n;i++){
		if(d1[i]==d2[i] && d1[i]+d2[i]==d1[t]){
			ans=(ans+mod-(w1[i]*w1[i])%mod*w2[i]%mod*w2[i]%mod)%mod;
		}
	}
	
	for(ll i=1;i<=2*m;i++){
		ll fr=ed[i].fr,tt=ed[i].tt,len=ed[i].len;
		
		if(max(d1[fr],d2[tt])*2<d1[t] && d1[fr]+d2[tt]+len==d1[t]){
			ans=(ans+mod-w1[fr]%mod*w1[fr]%mod*w2[tt]%mod*w2[tt]%mod)%mod;
		}
	}
	
	cout<<ans%mod<<endl;
	
	return 0;
}