#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
using namespace std;

const int lim=3005;


ll dp[lim][lim];

int n;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>dp[i][i];

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=max(dp[i][i]-dp[i+1][j],dp[j][j]-dp[i][j-1]);
		}
	}
	
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++) dp[j+1-i][j]=max(dp[j+1-i][j+1-i]-dp[j+2-i][j],dp[j][j]-dp[j+1-i][j-1]);
	}
	//printf("CHECK %lld %lld\n",dp[1][2],dp[2][3]);
	cout<<dp[1][n];
	return 0;
}