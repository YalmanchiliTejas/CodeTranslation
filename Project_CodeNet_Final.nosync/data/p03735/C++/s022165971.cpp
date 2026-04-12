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
#define SZ 666666
int n; pii ps[SZ];
int main()
{
	scanf("%d",&n);
	int mi=1e9,mx=0;
	#define rec(g) if(g<mi) mi=g; if(g>mx) mx=g;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&ps[i].fi,&ps[i].se);
		if(ps[i].fi>ps[i].se) swap(ps[i].fi,ps[i].se);
		rec(ps[i].fi) rec(ps[i].se)
	}
	#undef rec
	ll ans=1e18;
	int ma=-1e9,mb=1e9;
	for(int i=1;i<=n;++i)
		ma=max(ma,ps[i].fi),mb=min(mb,ps[i].se);
	ans=min(ans,(ma-mi)*ll(mx-mb));
	sort(ps+1,ps+1+n);
	ma=ps[n].fi; int lm=1e9;
	for(int i=1;i<=n;++i)
		ans=min(ans,(mx-mi)*ll(ma-min(ps[i].fi,lm))),
		ma=max(ma,ps[i].se),lm=min(lm,ps[i].se);
	printf("%lld\n",ans);
}
