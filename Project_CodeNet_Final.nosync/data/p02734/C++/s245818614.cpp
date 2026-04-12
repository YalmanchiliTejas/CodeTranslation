#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807;
const ll half_inf = 0x3f3f3f3f;
const ll inf = 0x7fffffff;
const ll mod = 998244353;
const ll maxn = 200005;
ll dp[3005]={0},a[3005],n,s,ans=0;
int main(){  
	cin.tie(0);
    ios::sync_with_stdio(false);
	scanf("%lld%lld",&n,&s);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		for(ll j=s-a[i];j>=0;j--){
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=mod;
		}
		dp[a[i]]+=i;
		ans+=dp[s];
		ans%=mod;
	}
	printf("%lld",ans);
    return 0;
}