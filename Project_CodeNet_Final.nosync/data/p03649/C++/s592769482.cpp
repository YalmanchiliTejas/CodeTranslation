#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
ll a[10000],ans,anss,n,i,l,r,b,delta,mid,t;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main ()
{
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if (a[1]<=n-1) 
	{
		printf("0\n");
		return 0;
	}
	while (1)
	{
		sort(a+1,a+1+n,cmp);
	//	pr(anss);
		//pr(ans);
		//for (i=1;i<=n;i++) printf("a[%lld]=%lld\n",i,a[i]+delta);
		if (a[1]+delta<=n-1) break;
		l=0,r=10000000000000000;
		ans=0;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (a[1]+delta-n*mid>n-1) 
			{
				l=mid+1;
				ans=mid;
			}
			else 
			{
				r=mid-1;
			}
		}
		delta+=ans;
		a[1]-=n*ans;
		a[1]-=ans;
		anss+=ans;
		if (ans==0) break;
	}
	while (1)
	{
		sort(a+1,a+1+n,cmp);
		if (a[1]+delta<=n-1) break;
		delta++;
		a[1]=a[1]-n-1;
		anss++;
	}
	printf("%lld\n",anss);
}