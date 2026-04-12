#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.1415926535897932384626
#define INF 1000000000
#define bits(n) __builtin_popcount(n)


void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll pref[n];
    pref[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+a[i];
    }
    ll res=0;
    for(int i=0;i<n-1;i++)
    {
        res=(res+((a[i]%mod)*((pref[n-1]-pref[i])%mod))%mod)%mod;
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
