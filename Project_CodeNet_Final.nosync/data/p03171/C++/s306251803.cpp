#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define all(x) x.begin(),x.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

ll find(vector<ll> &v,vector<vector<ll>> &dp,ll i,ll j,ll n)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll xx = i+n-1-j;
    if(xx%2)
    {
        return dp[i][j] = min(-v[i]+find(v,dp,i+1,j,n),-v[j]+find(v,dp,i,j-1,n));
    }
    else
    {
        return dp[i][j] = max(v[i]+find(v,dp,i+1,j,n),v[j]+find(v,dp,i,j-1,n));
    }
}

int main(){

    IOS;
    ll t,n,m,a,b,k;
    t=1;
    while(t--)
    {
        cin >> n;
        vector<ll> v(n);
        vector<vector<ll>> dp(n,vector<ll>(n,-1));
        for(ll i=0;i<n;i++) cin >> v[i];
        ll ans = find(v,dp,0,n-1,n);
        cout << ans << endl;
    }
    return 0;
}
