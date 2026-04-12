#include<bits/stdc++.h>
using namespace std;

const int MOD =  1e9 + 7;
#define int long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool gap;
int dp[3001][3001];

int solve(vector<int>&v,int l,int r)
{
    if(l > r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    if(((r-l)&1) != gap)
    {
        return dp[l][r] = max(v[l] + solve(v,l+1,r),v[r] + solve(v,l,r-1));
    }

    // cout<<l<<" "<<r<<endl;
    
    return dp[l][r] = min(-v[l] + solve(v,l+1,r),-v[r] + solve(v,l,r-1));
}

int32_t main()
{
	FASTIO;

	int n;
    cin>>n;

    memset(dp,-1,sizeof dp);

    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];

    if(n&1) gap = true;
    else gap = false;

    cout<<solve(v,0,n-1);


}