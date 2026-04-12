#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,dp[110][10][2];

signed main()
{
	ios::sync_with_stdio(false);
	string s;
	int k;
	cin>>s>>k;
	n=s.size();
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		int num=s[i-1]-'0';
		for(int j=0;j<=k;j++){
			for(int l=1;l<=9;l++){
				if(l==num){
					if(j<k) dp[i][j+1][0]+=dp[i-1][j][0];
					if(j<k) dp[i][j+1][1]+=dp[i-1][j][1];
				}
				else if(l>num){
					if(j<k) dp[i][j+1][1]+=dp[i-1][j][1];
				}
				else{
					if(j<k) dp[i][j+1][1]+=dp[i-1][j][0];
					if(j<k) dp[i][j+1][1]+=dp[i-1][j][1];
				}
			}
			if(num==0){
				dp[i][j][0]+=dp[i-1][j][0];
				dp[i][j][1]+=dp[i-1][j][1];
			}
			else{
				dp[i][j][1]+=dp[i-1][j][0];
				dp[i][j][1]+=dp[i-1][j][1];
			}
		}
	}
	cout<<dp[n][k][0]+dp[n][k][1]<<endl;
	return 0;
}