#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL a[N],s[N];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tests=1;
	//cin>>tests;
	while(tests--)
	{
		int n;
		scanf("%d",&n);

		LL sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			s[i]=(s[i-1]+a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			LL x=(a[i]*((s[n]-s[i])%1000000007))%1000000007;
			sum=(sum+x)%1000000007;
		}
		printf("%lld",sum);
	}
	return 0;
}

