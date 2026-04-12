#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = (int)1e9+7;
const int nax = 3004;

ll dp[nax][nax];
ll a[nax];
int n;
ll sum = 0;

ll solve(int i, int j){	
	if(i>j)
		return 0;
	if(i==j)
		return a[i];
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans = 0;
	ans = max(a[i] + min(solve(i+2,j),solve(i+1,j-1)),
			  a[j] + min(solve(i+1,j-1),solve(i,j-2))
			 );
	return dp[i][j] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			dp[i][j] = -1;
	}
	ll taro = solve(0,n-1);
	ll zira = sum - taro;
	cout<<taro-zira;
 
 
    return 0;
}







