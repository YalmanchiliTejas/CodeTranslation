#include<iostream>
using namespace std;
#define ll long long
int n;
ll a[3007],dp[3007][3007],pre[3007];
ll dfs(int l,int r){
	if(l==r){
		return a[l];
	}
	if(dp[l][r]!=0)return dp[l][r];
	return dp[l][r]=(pre[r]-pre[l-1])-min(dfs(l+1,r),dfs(l,r-1));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	ll ans1=dfs(1,n);
	ll ans2=pre[n]-ans1;
	printf("%lld\n",ans1-ans2);
}
