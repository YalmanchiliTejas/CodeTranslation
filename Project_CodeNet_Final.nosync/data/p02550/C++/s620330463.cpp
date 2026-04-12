#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define mod 998244353
#define string_mod 2549536629329_base_255
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define ss second
#define all(v) v.begin(), v.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
void solve()
{
    int n, x, m;
    cin >> n >> x >> m;
    int ans = x;
    int f = x;
    int vis[m + 1] = {0};
    vis[f] = 1;
    int k = 1;
    while (1 && k < n)
    {
        f = (f % m * f % m) % m;
        if (vis[f] == 1)
        {
            break;
        }
        vis[f] = 1;
        ans += f;
        k++;
    }
    if(k==n){
        cout << ans;
        return;
    }
    int c = 0;
    int g = 0;
    memset(vis, 0, sizeof(vis));
    while (1&&k<n)
    {
        if (vis[f] == 1)
            break;
        vis[f] = 1;
        c++;
        f = (f % m * f % m) % m;
        g += f;
        k++;
    }
    
    ans +=g+ g *((n - k) / c);
    g = n - k;
    g %= c;
    for (int i = 0; i < g;i++){
        ans += f;
        f = (f % m * f % m) % m;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    tc = 1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}