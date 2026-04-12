#include<iostream>
#include<cstdio>
using namespace std;
int a[200010];
long long s[200010];
int mod=1e9+7;
int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=((a[i]*s[i-1])%mod+ans)%mod;
		s[i]=(s[i-1]%mod+a[i]%mod)%mod;
	}
	printf("%lld\n",ans%mod);
}