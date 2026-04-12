#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int n,k;
ll ans;
int main()
{
	scanf("%d%d",&n,&k);
	if(k==0) {printf("%lld\n",(ll)n*n);return 0;}
	for(int i=k+1;i<=n;++i)
	{
		int A=n/i;
		ans+=A*(i-k);
		A=n-A*i;
		ans+=max(0,A-k+1);
	}
	cout<<ans<<endl;
	return 0;
}