#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,x[SZ],y[SZ],id[SZ];
bool cmpx(int a,int b)
{
	return x[a]<x[b];
}
bool cmpy(int a,int b)
{
	return y[a]<y[b];
}
int dis(int a,int b)
{
	return min(abs(x[a]-x[b]),abs(y[a]-y[b]));
}
int dis(pii x)
{
	return dis(x.fi,x.se);
}
pii ps[SZ];
bool cmp(pii a,pii b)
{
	return dis(a)<dis(b);
}
int ff[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",x+i,y+i);
		id[i]=i;
	}
	int g=0;
	sort(id+1,id+1+n,cmpx);
	for(int i=2;i<=n;i++)
		ps[++g]=pii(id[i-1],id[i]);
	sort(id+1,id+1+n,cmpy);
	for(int i=2;i<=n;i++)
		ps[++g]=pii(id[i-1],id[i]);
	sort(ps+1,ps+1+g,cmp);
	ll ans=0;
	for(int i=1;i<=g;i++)
	{
		int a=ps[i].fi,b=ps[i].se,c=dis(ps[i]);
		int ga=gf(a),gb=gf(b);
		if(ga==gb) continue;
		ff[ga]=gb; ans+=c;
	}
	printf("%lld\n",ans);
}