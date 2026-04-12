#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1000000+10;
ll dp[maxn];
ll a[maxn];
int n;

void solve(){
	memset(dp,INF,sizeof(dp));
	for(int i=n;i>=1;i--){
		*upper_bound(dp,dp+n,a[i])=a[i];
	}
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}

int main()
{
	while(~scanf("%d",&n) && n){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
