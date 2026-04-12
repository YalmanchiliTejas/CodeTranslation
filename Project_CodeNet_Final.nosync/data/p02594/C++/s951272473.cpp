#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree <int,null_type,less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// #include <ext/rope>
// using namespace __gnu_cxx;
typedef long long int ll;
typedef long double ld;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rep(g, i, n) for (ll g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define ve vector
#define lb lower_bound
#define ub upper_bound
#define bb break
#define cc continue
#define rem 1000000007
#define PI 3.141592653589793238462643383279502
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
struct point
{
    ll x, y;
};
int main()
{
    FAST
    // freopen("input1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    /*ll tests;
    cin>>tests;
    rep (gg,0,tests)
    {}*/
    ll x;
    cin>>x;
    if (x>=30)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
