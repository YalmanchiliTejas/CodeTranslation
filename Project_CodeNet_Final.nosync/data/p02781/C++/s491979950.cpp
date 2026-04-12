#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll n = s.size();
    vector<vector<vector<ll> > > dp(n,vector<vector<ll> >(k+1,vector<ll>(2,0) ) );
    for(int i=1;i<n;i++)dp[i][1][0]=9;
    dp[0][1][0] = (s[0]-'0')-1;
    dp[0][1][1] = 1;
    for(int i=1;i<n;i++){
	if( s[i] =='0' ){
	    for(int j=1;j<=k;j++){
		dp[i][j][1] +=dp[i-1][j][1];
	    }
	    for(int j=1;j<=k;j++){
		dp[i][j][0] += dp[i-1][j-1][0]*9 + dp[i-1][j][0];
	    }
	}else{
	    for(int j=1;j<=k;j++){
		dp[i][j][1] +=dp[i-1][j-1][1];
	    }
	    for(int j=1;j<=k;j++){
		dp[i][j][0] += dp[i-1][j-1][0]*9 + dp[i-1][j][0] + dp[i-1][j-1][1]* ((s[i]-'0')-1) + dp[i-1][j][1];
	    }
	}
    }
    ll res = 0;
  //  cout<<dp[n-1][k][0]<<' '<<dp[n-1][k][1]<<endl;
    //for(ll i=0;i<=k;i++)
	res += dp[n-1][k][0] + dp[n-1][k][1];
    cout<<res<<endl;
    return 0;
}
