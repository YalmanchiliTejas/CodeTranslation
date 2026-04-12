#include <bits/stdc++.h>
using namespace std;

const int M=2e5+5;
const int MO=1e9+7;
int a[M];

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int sum=a[0],ans=0;
	for(int i=1;i<n;i++)
	{
		ans=(ans+1LL*a[i]*sum%MO)%MO;
		sum=(sum+a[i])%MO;
	}
	printf("%d\n",ans);
	return 0;
}