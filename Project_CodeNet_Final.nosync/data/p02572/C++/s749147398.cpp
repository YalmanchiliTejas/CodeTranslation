#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define N 1000001
#define NN 1001
using namespace std;
LL n,a[N];
LL mod=1000000007;
int main()
{
	cin>>n;
	long long s=0,sum=0;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(LL i=1;i<=n;i++)
	{
		sum-=a[i];
		s=(((a[i]%mod)*(sum%mod)%mod)+s)%mod;
	}
	cout<<s<<endl;
	return 0;		
}
