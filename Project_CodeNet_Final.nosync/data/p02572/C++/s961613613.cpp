#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=200050;
ll a[MAXN],sum[MAXN];
void solve(int T){
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		sum[i]%=MOD; 
	}
	for(int i=1;i<=n;i++){
		ans+=(a[i]*((sum[n]-sum[i]+MOD)%MOD))%MOD;
		ans%=MOD; 
	}
	printf("%lld",ans);
}
signed main(){
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve(i);
	}
}