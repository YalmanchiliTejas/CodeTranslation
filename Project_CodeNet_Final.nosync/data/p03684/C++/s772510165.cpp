#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long  long
using namespace std;
int X[100010],Y[100010],n,a[100010];
struct node{
	int x,y,c;
}b[200010];int len=0;
bool cmp1(int a,int b) {return X[a]<X[b];}
bool cmp2(int a,int b) {return Y[a]<Y[b];}
bool cmp(node a,node b) {return a.c<b.c;}
void ins(int x,int y,int c) {b[++len].x=x;b[len].y=y;b[len].c=c;}
int fa[100010];
int findfa(int x) {return fa[x]==x?x:fa[x]=findfa(fa[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&X[i],&Y[i]);
	for(int i=1;i<=n;i++) a[i]=i;sort(a+1,a+n+1,cmp1);
	for(int i=2;i<=n;i++) ins(a[i-1],a[i],min(abs(X[a[i]]-X[a[i-1]]),abs(Y[a[i]]-Y[a[i-1]])));
	for(int i=1;i<=n;i++) a[i]=i;sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=n;i++) ins(a[i-1],a[i],min(abs(X[a[i]]-X[a[i-1]]),abs(Y[a[i]]-Y[a[i-1]])));
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	LL ans=0;
	for(int i=1;i<=len;i++)
	{
		int x=findfa(b[i].x),y=findfa(b[i].y);
		if(x!=y) fa[x]=y,ans+=b[i].c;
	}
	printf("%lld",ans);
}