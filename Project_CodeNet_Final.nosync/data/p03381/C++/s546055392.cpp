//#include<iostream>
#include<cstring>
#include<cstdio>
//#include<time.h>
//#include<complex>
//#include<set>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int n;
#define maxn 200011
struct Node{int v,id;}a[maxn];
bool cmp(const Node &a,const Node &b) {return a.v<b.v;}
int ans[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[a[i].id=i].v);
	sort(a+1,a+1+n,cmp);
	for (int i=1,to=n>>1;i<=to;i++) ans[a[i].id]=a[to+1].v;
	for (int i=n,to=n>>1;i>to;i--) ans[a[i].id]=a[to].v;
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}