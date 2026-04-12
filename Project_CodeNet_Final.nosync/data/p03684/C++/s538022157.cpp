#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
const int maxn = 1000050;
const int zqc = 1e9+7;
typedef long long ll;

int n, cnt, fa[maxn];
struct node{int x,y,id;}a[maxn];
struct edge{int u,v,w;}e[maxn];

bool cmp(node a,node b){return a.x<b.x;}
bool cmp2(node a,node b){return a.y<b.y;}
bool cmp3(edge a,edge b){return a.w<b.w;}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}

int main()
{
	scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	fo(i,1,n-1) e[++cnt] = (struct edge){a[i].id,a[i+1].id,a[i+1].x-a[i].x};
	sort(a+1,a+n+1,cmp2);
	fo(i,1,n-1) e[++cnt] = (struct edge){a[i].id,a[i+1].id,a[i+1].y-a[i].y};
	fo(i,1,n) fa[i] = i;
	sort(e+1,e+cnt+1,cmp3);
	int k = n-1, a, b; ll ans = 0;
	fo(i,1,cnt)
	{
		a = getfa(e[i].u); b = getfa(e[i].v);
		if(a != b)
		{
			ans += e[i].w;
			fa[a] = b;
			-- k;
			if(!k) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}