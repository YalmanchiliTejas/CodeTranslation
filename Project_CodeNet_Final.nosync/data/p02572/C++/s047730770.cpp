#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 1010
#define N 1000000
#define LL long long
#pragma GCC optimize(2)
using namespace std;
LL mod=1e9+7,a[N],sum=0,n,ans=0;
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		ans-=a[i];
		sum=sum%mod+(ans%mod)*(a[i]%mod)%mod;
		sum%=mod;
	}
	cout<<sum%mod;
	return 0;
}
/*
*/
