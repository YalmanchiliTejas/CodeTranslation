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

int main()
{
    jaldi
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int &x:v) cin>>x;

    ll dp[inp][inp];

    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(r==l) { dp[l][r]=v[l]; continue; }
            dp[l][r] = max( v[l]-dp[l+1][r] , v[r]-dp[l][r-1] );
        }
    }
    cout<<dp[0][n-1];

    return 0;
}
