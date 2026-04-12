#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
long long ans;
int main()
{
	scanf("%d%d",&n,&k);
	if (k==0) {printf("%lld",1ll*n*n);return 0;} 
	for (int i=k+1;i<=n;i++)
	{
		int q=n/i;
		ans+=1ll*q*(i-k);
		ans+=max(0,n%i-k+1);
		//cout<<ans<<endl;
	}
	printf("%lld",ans);
}