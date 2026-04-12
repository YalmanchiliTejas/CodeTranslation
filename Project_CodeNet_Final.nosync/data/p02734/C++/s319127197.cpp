#include <bits/stdc++.h>
#define ll long long
#define cwk freopen("D:\\c++\\in.txt","r",stdin),freopen("D:\\c++\\out.txt","w",stdout)
using namespace std;
const int N=1e6+10;
const int mod=998244353;
int n,s,a[N];
ll dp[N];
int main()
{
	//cwk;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++) {
		dp[0]++;
		for(int j=s;j>=a[i];j--) {
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		ans=(ans+dp[s])%mod;
	}
	printf("%lld\n",ans);

	return 0;
}