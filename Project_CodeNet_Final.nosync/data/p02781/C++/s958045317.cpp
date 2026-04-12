#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,dp[105][2][5],K;
int main(){
	cin>>s>>K;n=s.size();s="$"+s;
	for (int i=1;i<=n;i++) s[i]-='0';
	dp[0][1][0]=1;
	for (int i=1;i<=n;i++){
		for(int k=0;k<=K;k++){
			if (s[i]==0) dp[i][1][k]+=dp[i-1][1][k],dp[i][0][k]+=dp[i-1][0][k];
			else dp[i][0][k]+=dp[i-1][0][k]+dp[i-1][1][k];
			for (int j=1;j<10;j++){
				if (s[i]<j){
					dp[i][0][k+1]+=dp[i-1][0][k];
				}
				if (s[i]>j){
					dp[i][0][k+1]+=dp[i-1][0][k]+dp[i-1][1][k];
				}
				if (s[i]==j){
					dp[i][1][k+1]+=dp[i-1][1][k];
					dp[i][0][k+1]+=dp[i-1][0][k]; 
				}
			}
		}
	}
	cout<<dp[n][1][K]+dp[n][0][K];
}