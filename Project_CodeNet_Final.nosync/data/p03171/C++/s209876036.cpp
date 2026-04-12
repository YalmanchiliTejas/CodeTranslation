#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define fast_io         ios_base::sync_with_stdio(false); cin.tie(NULL);


int main(){
    fast_io;
    
    ll n;
    cin >> n;

    vector<ll> v(n);
    vector<ll> cumSum(n+1);
    cumSum[0] = 0;

    for(ll i=0; i<n; i++){
    	cin >> v[i];
    	cumSum[i+1] = v[i] + cumSum[i];
    }

    vector<vector<ll>> dp(3002, vector<ll>(3002, 0));

    // lenght dp
    ll i,j;

    
    for(ll k=0; k<n; k++){
    	i = 0;
    	j = k;

    	while(i<n and j<n){
    		if(i == j){
    			dp[i][j] = v[i];
    			i++;
    			j++;
    			continue;
    		}
    		else{
    			dp[i][j] = v[i] + cumSum[j+1] - cumSum[i+1] - dp[i+1][j];
	    		dp[i][j] = max(dp[i][j], v[j] + cumSum[j] - cumSum[i] - dp[i][j-1]);

	    		i++;
	    		j++;
    		}    		
    	}
    }
    
    ll ans = dp[0][n-1] - (cumSum[n] - dp[0][n-1]);

    cout<<ans<<"\n";
    
	return 0;
}