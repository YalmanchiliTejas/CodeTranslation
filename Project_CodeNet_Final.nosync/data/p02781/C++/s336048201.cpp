#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9+7;
const ll INF = 1<<30;

int main(){
	ull dp[105][4][2];
	string s;
	int k;
	
	cin>>s;
	cin>>k;
	
	memset(dp, 0, sizeof dp);
	dp[s.size()][0][0] = 1;
	dp[s.size()][0][1] = 1;

	for(int i=s.size()-1;i>=0;i--){
		//cout<<i<<":";
		dp[i][0][0] = dp[i+1][0][0];
		dp[i][0][1] = dp[i+1][0][1];
		//cout<<dp[i][0][0]<<","<<dp[i][0][1]<<" ";
		for(int j=1;j<=k;j++){
			dp[i][j][1] = 9*dp[i+1][j-1][1] + dp[i+1][j][1];
			if(s[i] == '0'){
				dp[i][j][0] = dp[i+1][j][0];
			} 
			else{
				dp[i][j][0] = (s[i]-'0'-1)*dp[i+1][j-1][1] + dp[i+1][j][1] + dp[i+1][j-1][0];
			}
			//cout<<dp[i][j][0]<<","<<dp[i][j][1]<<" ";
		}
		//cout<<"\n";
	}

	cout<<dp[0][k][0]<<"\n";
	
	return 0;
}

/*

dp[i][j] = No. of numbers possible with j non-zero digit such that d[i+j]<=s[i+j];i<=i+j<=|s|


*/