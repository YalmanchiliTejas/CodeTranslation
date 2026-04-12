#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef vector <ll> vll;
typedef pair <ll, ll> pll;
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define all(_) _.begin(), _.end()
#define F first
#define S second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll f[MAX];
ll modex(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
ll ncr(ll n, ll r)
{
    if(r == 0 || r == n)
        return 1;
    ll ans = f[n];
    ans = (ans * modex(f[n - r], mod - 2)) % mod;
    ans = (ans * modex(f[r], mod - 2)) % mod;
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n, m, i, k;
    f[0] = 1;
    for(i = 1; i < MAX; i++)
        f[i] = (f[i - 1] * i) % mod;
    cin >> n >> m >> k;
    ll ans = ncr(n * m - 2, k - 2);
    ll e1 = ((m % mod) * (n * n - 1) % mod) % mod;
    ll e2 = ((n % mod) * (m * m - 1) % mod) % mod;
    // cout << e1 << ' ' <<  e2 << endl;
    e1 = (e1 + e2) % mod;
    // cout << e1 << ' ' <<  e2 << endl;
    e1 = (e1 * (n * m) % mod) % mod;
    e1 = (e1 * modex(6, mod - 2)) % mod;
    // cout << e1 << ' ' <<  e2 << endl;
    // cout << ans << endl;
    ans = (ans * e1) % mod;
    cout << ans << endl;
    return 0;
}