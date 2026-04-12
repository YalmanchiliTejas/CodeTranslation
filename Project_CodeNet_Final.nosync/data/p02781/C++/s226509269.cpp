#include<bits/stdc++.h>
using namespace std;
char n[109];
int k,dp[109][5],limit[109][5];
int main() {
	scanf("%s%d",n,&k);
	int len=strlen(n);
	dp[0][0]=1;
	dp[0][1]=n[0]-'0';
	limit[0][1]=n[0]=='0'?0:1;
	limit[0][0]=n[0]=='0'?1:0;
	for(int i=0;i+1<len;i++)
		for(int j=0;j<=min(k,i+1);j++) {
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j+1]+=dp[i][j]*9-limit[i][j]*(9-n[i+1]+'0');
			limit[i+1][j]+=(n[i+1]=='0'?limit[i][j]:0);
			limit[i+1][j+1]+=(n[i+1]=='0'?0:limit[i][j]);
		}
	printf("%d\n",dp[len-1][k]);
	return 0;
}