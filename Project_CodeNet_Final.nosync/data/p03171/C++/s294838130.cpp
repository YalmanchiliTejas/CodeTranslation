#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  3005

ll n,sum;
ll a[N];
ll dp[N][N];
ll dps(ll l,ll r)
{
    if(l>r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    dp[l][r]=max(a[l]+min(dps(l+2,r),dps(l+1,r-1)),a[r]+min(dps(l,r-2),dps(l+1,r-1)));
    return dp[l][r];
}   
void solve()
{
    cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<2*dps(0,n-1)-sum<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}