#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define debug(x) {cout<<(#x)<<" "<<x<<endl;}
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1; char ch=getchar();
    while (!(ch>='0'&&ch<='9')) {if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

const int N = 100005;
const int M = 500005;

struct Point {
	int x,y,id;
} p[N];
inline bool cmp1(const Point &a,const Point &b) {return a.x<b.x;}
inline bool cmp2(const Point &a,const Point &b) {return a.y<b.y;}

int n;
int fa[N];
LL ans=0;

int tot=0;
struct edge{
	int u,v,w;
} e[M];
inline bool cmp3(const edge &a,const edge &b) {return a.w<b.w;}

int getfather(int x) {return (fa[x]==x)?x:(fa[x]=getfather(fa[x]));}

int main() {

	#ifndef ONLINE_JUDGE
	//	freopen("data.in","r",stdin);
	//	freopen("data.out","w",stdout);
	#endif

	n=read(); rep(i,1,n) p[i].x=read(),p[i].y=read(),p[i].id=i;
	sort(p+1,p+n+1,cmp1);
	rep(i,2,n) ++tot,e[tot].u=p[i-1].id,e[tot].v=p[i].id,e[tot].w=p[i].x-p[i-1].x;
	sort(p+1,p+n+1,cmp2);
	rep(i,2,n) ++tot,e[tot].u=p[i-1].id,e[tot].v=p[i].id,e[tot].w=p[i].y-p[i-1].y;
	sort(e+1,e+tot+1,cmp3);
	rep(i,1,n) fa[i]=i;
	int num=0;
	rep(i,1,tot) {
		int x=getfather(e[i].u),y=getfather(e[i].v);
		if (x!=y) {
			fa[x]=y; num++;
			ans+=e[i].w;
		}
	}
	assert(num==n-1);
	printf("%lld\n",ans);


	return 0;
}
