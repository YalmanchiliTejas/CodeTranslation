#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define inp 3005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007 
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;

// Pick yourself up, 'cause...

// max ans. if i have an array i to j

vector<vector<ll>> dp(inp,vector<ll>(inp,-1));
vector<ll> pre(inp,0);

ll func(int i,int j)
{
    if(i==j) return pre[i]-pre[i-1];
    if(dp[i][j]!=-1) return dp[i][j];

    ll sum = pre[j]-pre[i-1]; //sum in these segment
    dp[i][j] = max(pre[i]-pre[i-1] + (pre[j]-pre[i]-func(i+1,j)) , pre[j]-pre[j-1] + (pre[j-1]-pre[i-1]-func(i,j-1)) );
    return dp[i][j];
}

int main()
{
    jaldi
    
    int n;
    cin>>n;

    vector<ll> v(n);
    for(ll &x:v) cin>>x;

    for(int i=1;i<=n;i++) { pre[i]=pre[i-1]+v[i-1]; }
    //deb(pre);
    ll first = func(1,n);
    ll second = pre[n]-first;
    cout<<first-second;

    return 0;
}
