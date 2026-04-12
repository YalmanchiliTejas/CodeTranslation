/* Life is all about calculated risks.
    But man am I bad at math. */

#include <bits/stdc++.h> 
#define ll long long int
#define INF (ll)1e12
#define MOD 1000000007

#define DEBUG(x) cerr<<"> "<< #x << ':' <<x<<endl;

using namespace std;

ll f(ll st, ll end);

ll n;
ll a[3010];

vector<vector<ll>> dp(3010, vector<ll>(3010, -1));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    ll X = f(1,n);
    ll Y = min( f(2,n) , f(1,n-1) );

    cout<<X-Y<<endl;

    return 0;
}

ll f(ll st, ll end)
{
    if(dp[st][end] != -1)
    {
        return dp[st][end];
    }

    if(st > end)
    {
        return 0;
    }

    return dp[st][end] = max( a[st] + min(f(st+2,end),f(st+1,end-1)) , a[end] + min(f(st+1,end-1),f(st,end-2)) );
}