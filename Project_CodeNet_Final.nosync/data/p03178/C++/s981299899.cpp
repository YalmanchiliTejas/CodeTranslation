#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int MAXM=105;
const int MOD=1e9+7;
int dp[MAXN][MAXM];
int num[MAXN],d;
char s[MAXN];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i){
		num[i]=s[i]-'0';
	}
	cin>>d;
	dp[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<d;++j){
			for(int k=0;k<10;++k){
				(dp[i+1][(j+k)%d]+=dp[i][j])%=MOD;
			}
		}
	}
	int ans(0);
	int sum(0);
	for(int i=1;i<=n;++i){
		for(int z=0;z<num[i];++z){
			(ans+=dp[n-i][(d+d-sum-z)%d])%=MOD;
		}
		(sum+=num[i])%=d;
	}
	ans+=(!sum);
	(ans+=MOD-1)%=MOD;
	cout<<ans<<endl;
	return 0;
}