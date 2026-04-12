#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int n; cin>>n;
	ll a[n+1], pref[n+1] = {0};
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    if(i==1) pref[1] = a[1];
	    else if(i&1) pref[i] = pref[i-2] + a[i];
	}
	//for(auto it:pref) cout<<it<<' '; cout<<'\n';
	ll dp[n+1] = {0};
	dp[1] = 0;
	for(int i=2;i<=n;i++)
	{
	    if(i&1) dp[i] = max(dp[i-1],dp[i-2]+a[i]);
	    else dp[i] = max(dp[i-2]+a[i],pref[i-1]);
	}
	//for(auto it:dp) cout<<it<<' '; cout<<'\n';
	cout<<dp[n];
	
	
	return 0;
}
