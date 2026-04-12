#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e3;
const int mod = 998244353;
int dp[N+100][N+100],S,A[N+100],n;

int solve(int pos,int total)
{
	if(total==S){
		return n+2-pos;
	}
	if(pos==n+1){
		return 0;
	}
	if(total>S){
		return 0;
	}
	if(dp[pos][total]!=-1){
		return dp[pos][total];
	}
	int sum = 0;
	sum = (sum+solve(pos+1,total+A[pos]))%mod;
	sum = (sum+solve(pos+1,total))%mod;
	return dp[pos][total] = sum;
}
int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++){
		scanf("%d",A+i);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ll cur = (1ll*solve(i+1,A[i])*i)%mod;
		ans = (ans+cur)%mod;
	}
	printf("%lld\n",ans);
}
