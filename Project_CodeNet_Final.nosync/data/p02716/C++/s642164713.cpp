#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
const int MAXN=2e5+10;
ll val[MAXN],pre[MAXN],suf[MAXN],dp[MAXN];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
	if(n%2==0){
        pre[1]=val[1];pre[2]=val[2];
        for(int i=3;i<=n;i++) pre[i]=pre[i-2]+val[i];
        suf[n]=val[n];suf[n-1]=val[n-1];
        for(int i=n-2;i>=1;i--) suf[i]=suf[i+2]+val[i];
		ll ans=max(pre[n-1],pre[n]);
		for(int i=1;i<=n-3;i+=2) ans=max(ans,pre[i]+suf[i+3]);
		printf("%lld\n",ans);
		return 0;
	}
	ll mx=dp[1]=-val[1];
	ll sum=val[1];
	for(int i=3;i<=n;i+=2){
        sum+=val[i];
        dp[i]=max(-val[i],dp[i-2]+val[i-1]-val[i]);
        mx=max(mx,dp[i]);
	}
	printf("%lld\n",sum+mx);
	return 0;
}
