#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e5+100,M=4e5+100;
const int mod=1e9+7;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int head[N],nxt[M],to[M],w[M],n;
struct Q{ int k; LL dis; inline bool operator < (const Q &b) const { return dis>b.dis; } };
struct Graph{
	LL dis[N];int f[N];bool out[N];
	inline void shortroad(int k) {
		int i;priority_queue<Q>q;
		for (i=1;i<=n;i++) dis[i]=OO;
		q.push((Q){k,dis[k]=0});f[k]=1;
		while (!q.empty()) {
			k=q.top().k;q.pop();
			if (out[k]) continue;out[k]=true;
			for (i=head[k];i;i=nxt[i])
				if (dis[k]+w[i]<dis[to[i]])
					q.push((Q){to[i],dis[to[i]]=dis[k]+w[i]}),f[to[i]]=f[k];
				else if (dis[k]+w[i]==dis[to[i]])
					(f[to[i]]+=f[k])%=mod;
		}
	}
}G1,G2;
int main()
{
	n=gi();int m=gi(),i,S=gi(),T=gi(),a,b,ans,tot=1,t;
	for (i=1;i<=m;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
		w[tot]=w[tot-1]=gi();
	}
	G1.shortroad(S);
	G2.shortroad(T);
	ans=1LL*G1.f[T]*G2.f[S]%mod;
	for (i=1;i<=n;i++)
		if (G1.dis[i]+G2.dis[i]==G1.dis[T]&&G1.dis[i]==G2.dis[i])
			t=1LL*G1.f[i]*G2.f[i]%mod,ans=(ans-1LL*t*t)%mod;
	for (i=2;i<=tot;i++) {
		a=to[i^1],b=to[i];
		if (G1.dis[a]+G2.dis[b]+w[i]==G1.dis[T]&&G1.dis[a]<G2.dis[a]&&G1.dis[b]>G2.dis[b])
			t=1LL*G1.f[a]*G2.f[b]%mod,ans=(ans-1LL*t*t)%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
