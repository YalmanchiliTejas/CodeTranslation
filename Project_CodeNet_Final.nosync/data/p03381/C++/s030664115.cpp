#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200005;
struct Node{
	int x,id;
}a[N];
int n,rk[N],b[N];
bool cmp(Node x,Node y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i].x),b[i]=a[i].x,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) rk[a[i].id]=i;
//	for(int i=1;i<=n;i++) cout<<rk[i];
	int v1,v2;
	for(int i=1;i<=n;i++)
	  if(rk[i]==n/2) v1=b[i];
	    else if(rk[i]==n/2+1) v2=b[i];
	for(int i=1;i<=n;i++)
	  if(rk[i]<=n/2) printf("%d\n",v2);
	    else printf("%d\n",v1);
	return 0;
}