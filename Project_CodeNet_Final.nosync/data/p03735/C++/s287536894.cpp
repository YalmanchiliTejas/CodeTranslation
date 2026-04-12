#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	long long x,y;
}a[200005];
long long mny[200005],mxy[200005],ymx[200005];
bool cmp(node t1,node t2)
{
	return t1.x<t2.x;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	long long mn=1e9,mx=0;
	mny[0]=1e9;
	for (int i=1; i<=n; i++)
	{
		mn=min(mn,a[i].y);
		mx=max(mx,a[i].y);
		mny[i]=min(mny[i-1],a[i].y);
		mxy[i]=max(mxy[i-1],a[i].y);
	}
	for (int i=n; i>=1; i--) ymx[i]=max(ymx[i+1],a[i].y);
	long long ans=(mx-mn)*(a[n].x-a[1].x);
	for (int i=1; i<n; i++)
	{
		long long minA=min(a[i+1].x,mny[i]);
		long long maxA=max(a[n].x,mxy[i]);
		long long minB=a[1].x;
		long long maxB=ymx[i+1];
		//printf("%d %lld %lld %lld %lld\n",i,minA,maxA,minB,maxB);
		ans=min(ans,(maxB-minB)*(maxA-minA));
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1、max,min不同
2、max,min同
  设min,max在B
  A:前a个选y，后(n-a)个选x
  B:………………x，……………………………y
  对于第k个，从选x变成选y至A的影响
  minA=min(xk+1,y(1~k)mn)；maxA=max(xn,y(1~k)mx);
  minB=x1;maxB=max(y(k+1~n))
*/
/*
3
1 2
3 4
5 6
*/