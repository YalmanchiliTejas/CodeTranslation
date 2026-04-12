#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
// const ll MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll dp[n][n];
	int flag = n&1;
	for(int i=0;i<n;i++){
		if(flag)
			dp[i][i] = a[i];
		else
			dp[i][i] = -a[i];
	}

	for(int k=1;k<n;k++){
		flag = 1-flag;
		for(int i=0;i<n-k;i++){
			if(flag)
				dp[i][i+k] = max(dp[i][i+k-1]+a[i+k],dp[i+1][i+k]+a[i]);	
			else
				dp[i][i+k] = min(dp[i][i+k-1]-a[i+k],dp[i+1][i+k]-a[i]);
		}
	}
	
	cout<<dp[0][n-1]<<endl;
}
