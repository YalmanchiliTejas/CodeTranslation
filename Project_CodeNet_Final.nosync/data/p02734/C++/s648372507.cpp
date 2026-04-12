#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10,mod=998244353;
int n,s,v,dp[N],ans;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i){
		scanf("%d",&v);
		for(int j=s;j>v;--j){//从原有的合法序列l,r属于[L,R-1] 补一个R 
			dp[j]=(dp[j]+dp[j-v])%mod; 
		}
		dp[v]=(dp[v]+i)%mod;//r=R l从1到r取共i种 
		ans=(ans+dp[s])%mod;
	}
	printf("%d",ans);
	return 0;
} 