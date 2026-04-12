#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define pii 3.14
#define mod (ll)(1e9+7)
#define inf (ll)(1e18)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pi pair<int,int>
#define N (ll)(1e5 + 5)


void solve()
{
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    ll sum[n] = {0};
    sum[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
        sum[i] = (sum[i+1] + arr[i])%mod;

    ll ans = 0;
    for(int i=0;i<n-1;i++)
    {
        ll cur = (arr[i] * sum[i+1])%mod;
        ans = (ans + cur)%mod;
    }

    cout<<ans;
}

int main()
{
    fio;
    ll tc = 1;
    //cin>>tc;
    while(tc--)
    {
        solve();
    }
}
