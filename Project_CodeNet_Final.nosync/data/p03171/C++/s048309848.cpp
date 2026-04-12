#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	    ll int n;
	    cin>>n;
	    ll int arr[n];
	    for(ll int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    pair<ll int,ll int> dp[n][n];
	    for(ll int i = 0;i<n;i++){
	        dp[i][i].first   = arr[i];
	        dp[i][i].second  = 0;
	    }
	    for(ll int diff = 1;diff<n;diff++){
	        for(ll int i = 0;i<n-diff;i++){
	            int j = i+diff;
	            dp[i][j].first = 0;
	            dp[i][j].second = 0;

	            if(arr[j]+dp[i][j-1].second > dp[i][j].first){
	                dp[i][j].first  = arr[j]+dp[i][j-1].second;
	                dp[i][j].second = dp[i][j-1].first;
	            }
	            if(arr[i]+dp[i+1][j].second > dp[i][j].first){
	                dp[i][j].first  = arr[i]+dp[i+1][j].second;
	                dp[i][j].second = dp[i+1][j].first;
	            }

	        }
	    }
	    cout<<dp[0][n-1].first - dp[0][n-1].second<<endl;
}
