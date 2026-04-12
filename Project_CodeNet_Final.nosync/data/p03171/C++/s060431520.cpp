#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

ll minimax(ll i, ll j, ll n, vector< vector<ll> > & dp, vector<ll> &a)
{
    if(j<0 || i>=n || i>j)
        return ll_MAX;
   
    if(dp[i][j] != -1)
        return dp[i][j];
     if(i==j)
        return a[i];
    ll v1 = minimax(i + 1, j - 1, n, dp, a);
    ll v2 = minimax(i + 2, j, n, dp, a);
    ll v3 = minimax(i + 1, j - 1, n, dp, a);
    ll v4 = minimax(i, j - 2, n, dp, a);
    
    v1 = min(v1, v2);
    if(v1 == ll_MAX)
        v1 = ll_MIN;
    v3 = min(v3, v4);
    if(v3 == ll_MAX)
        v3 = ll_MIN;

    dp[i][j] = max(a[i] + v1, a[j] + v3);
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        /* code */
        ll x;
        cin>>x;
        sum += x;
        a.push_back(x);
    }
    vector< vector<ll> > dp(n, vector<ll>(n, -1));
    ll val = minimax(0, n - 1, n, dp, a);
    // cout<<val<<" "<<2*val<<'\n';
    cout<<2*val - sum<<'\n';
}