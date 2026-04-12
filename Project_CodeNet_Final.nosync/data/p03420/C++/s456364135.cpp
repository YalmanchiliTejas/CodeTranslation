#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	long long ans=0;
	for (int b=k+1;b<=n;b++)
	ans+=n/b*(b-k)+max(n%b-k+1,0);
	if (!k)
	ans-=n;
	printf("%lld",ans);
}