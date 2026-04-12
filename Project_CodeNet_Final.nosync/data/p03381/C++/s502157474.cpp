#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
using namespace std;
typedef long long ll;
typedef double db;
int n,ans[N],tmp;
struct node{int num,id;}a[N];
bool cmp(const node &T1,const node &T2){return T1.num<T2.num;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i].num),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	tmp=n/2+1;
	for(int i=1;i<=n/2;++i) ans[a[i].id]=a[tmp].num;
	tmp--;
	for(int i=n/2+1;i<=n;++i) ans[a[i].id]=a[tmp].num;
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	return 0;
}
