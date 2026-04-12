#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll int INF = 1e18 + 5;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n;
    cin>>n;
    ll int a[n];
    for(ll int i=0;i<n;i++){
    	cin>>a[i];
    }
    ll int dp[n+5][n+5] = {0};
    for(ll int l=n;l>=0;l--){
    	for(ll int r=l;r<n;r++){
    		if(l == r)
    			dp[l][r] = a[l];
    		else{
    			dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
    		}
    		// cout<<dp[l][r]<<" "<<l<<" "<<r<<endl;
    	}
    }
    cout<<dp[0][n-1]<<"\n";
	return 0;
}