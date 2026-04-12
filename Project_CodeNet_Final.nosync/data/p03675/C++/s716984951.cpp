#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int n,a[1000000],i;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n%2)
	{
		for (i=n;i>=1;i-=2) printf("%d ",a[i]);
		for (i=2;i<=n;i+=2) printf("%d ",a[i]);
	}
	else 
	{
		for (i=n;i>=1;i-=2) printf("%d ",a[i]);
		for (i=1;i<=n;i+=2) printf("%d ",a[i]); 
	}
	return 0;
}