#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200010,INF=2000000000;
ll a[N];
ll dp[N][3];
ll n;
template<class T>
T mx(T a,T b){
	if(a>b) return a;
	return b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(ll i=0;i<=n;++i){
		for(ll j=0;j<3;++j){
			dp[i][j]=-(ll)INF*INF;
		}
	}
	if(n&1){
		dp[1][0]=a[1];
		for(ll i=3;i<=n;i+=2) dp[i][0]=dp[i-2][0]+a[i];
		dp[2][1]=a[2];
		for(ll i=4;i<=n;i+=2) dp[i][1]=mx(dp[i-2][1],dp[i-3][0])+a[i];
		dp[3][2]=a[3];
		for(ll i=5;i<=n;i+=2) dp[i][2]=mx(mx(dp[i-2][2],dp[i-3][1]),dp[i-4][0])+a[i];
		printf("%lld",mx(mx(dp[n][2],dp[n-1][1]),dp[n-2][0]));
	}
	else{
		dp[1][0]=a[1];
		for(ll i=3;i<=n;i+=2) dp[i][0]=dp[i-2][0]+a[i];
		dp[2][1]=a[2];
		for(ll i=4;i<=n;i+=2) dp[i][1]=mx(dp[i-2][1],dp[i-3][0])+a[i];
		printf("%lld",mx(dp[n][1],dp[n-1][0]));
	}
}