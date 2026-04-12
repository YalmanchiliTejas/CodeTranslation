#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5 + 10, inf = 1e18 + 10, mod = 1e9 + 7;
ll a[3010], d[3010][3010][2];
ll f(int l, int r, int t)
{
    if(d[l][r][1] != -inf)
    {
        if(t)return d[l][r][1];
        else return d[l][r][0];
    }
    if(l == r)
    {
        if(t)return a[l];
        else return -a[l];
    }
    d[l][r][1] = max(f(l + 1, r, !t) + a[l], f(l, r - 1, !t) + a[r]);
    d[l][r][0] = min(f(l + 1, r, !t) - a[l], f(l, r - 1, !t) - a[r]);
    if(t)return d[l][r][1];
    else return d[l][r][0];
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("prices.in", "r", stdin);
    //freopen("prices.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            d[i][j][1] = -inf;
            d[i][j][0] = -inf;
        }
    }
    for(int i = 1; i <= n; i++)cin >> a[i];
    cout << f(1, n, 1);
}
