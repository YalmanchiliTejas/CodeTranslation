#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<utility>
#include<iostream>
using namespace std;
const int maxn = 2e5 + 233;
int a[maxn],ord[maxn],p[maxn];
bool cmp(const int A,const int B)
{
	return a[A]<a[B];
}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		ord[i] = i;
	sort(ord+1,ord+1+n,cmp);
	for(int i=1;i<=n;i++)p[ord[i]] = i;
	int t = n>>1;
//	for(int i=1;i<=n;i++)
//	cout<<p[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int x = p[i];
		if(x<=t) printf("%d\n",a[ord[t+1]]);
		else printf("%d\n",a[ord[t]]);
	}
	return 0; 
}