#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,l,r,mid,num[55],ans,now[55];
bool check(long long x)
{
	if (x<0) return 0;
	long long i,s=0;
	for (i=1;i<=n;i++) now[i]=num[i]+x;
	for (i=1;i<=n;i++)
	{
		if (now[i]>=n)
		{
			s+=(now[i]-(n-1)+n)/(n+1);
		}
	}
	return s<=x;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>num[i];
	/*sort(num+1,num+n+1);
	reverse(num+1,num+n+1);*/
	l=0;r=6e18;
	while (l<r)
	{
		mid=(l+r+1)/2;
		if (check(mid))
		{
			r=mid-1;
			ans=mid; 
		}
		else l=mid;
	}
	for (i=ans-5000;i<=ans+5000;i++)
	{
		if (i<0) continue;
		if (i>1e18) continue;
		if (check(i))
		{
			cout<<i;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}