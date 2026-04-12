#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=6010,P=998244353;
int n,s,a[MAXN],dp[MAXN],np[MAXN];
ll ans;
int main () {
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		for (int j=s;j>=1;j--) {
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%P;
		}
		dp[a[i]]=(dp[a[i]]+i)%P;
		np[i]=dp[s];
		ans=(ans+(1ll*((np[i]-np[i-1]+P)%P)*(n-i+1)))%P;
	}
	printf("%lld\n",ans);
	return 0;
}