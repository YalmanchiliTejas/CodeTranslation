#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N=3010;
const int MOD=998244353;
int dp[MAX_N],a[MAX_N];
int main(void){
	int n,s,i,j;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=s;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;	
		}
		if(a[i]<=s)
			dp[a[i]]=(dp[a[i]]+i)%MOD;
			ans=(ans+dp[s])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}