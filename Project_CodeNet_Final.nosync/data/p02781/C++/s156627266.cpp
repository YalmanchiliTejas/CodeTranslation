#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int dp[1000][5][2];
signed main(){
	string n;
	cin>>n;
	int k;
	cin>>k;
	int s = n.size();
	dp[0][1][0] = n[0] - '0' - 1;
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;
	for(int i=0;i<s-1;i++){
		for(int j=0;j<=3;j++){
			dp[i+1][j][0] += dp[i][j][0]; // next is 0
			dp[i+1][j+1][0] += dp[i][j][0] * 9; // next is 1-9
			if( n[i+1] == '0' ){
				dp[i+1][j][1] += dp[i][j][1]; // next is 0
			}
			else{
				dp[i+1][j][0] += dp[i][j][1];
				dp[i+1][j+1][0] += dp[i][j][1] * ( n[i+1] - '0' - 1);
				dp[i+1][j+1][1] += dp[i][j][1];
			}
		}
	}
	cout<<dp[s-1][k][0] + dp[s-1][k][1]<<endl;
	return 0;
}