/*
 *
 *    I am o0o0oo00.
 *
 */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll          long long
#define p7          1000000007
#define p9          998244353
#define pb          push_back
#define ff          first
#define ss          second
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define vpll        vector<pll>
#define mll         map<ll,ll>
#define test        ll T;cin>>T;while(T--)
#define ad(a,n)     vll a;a.resize(n);for(ll i=0;i<n;i++)cin>>a[i];
#define as(a,n)     for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define all(x)      x.begin(),x.end()

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll powm(ll x, ll y, ll m = p7) {
    x = x % m; ll res = 1; while (y)
    {if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
ll modi(ll a, ll m = p7) {return powm(a, m - 2, m);}
void yesno(bool f) {f ? cout << "YES" << endl : cout << "NO" << endl;}


void ss99()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

ll dp[3001][3001];

int32_t main()
{
    ss99();
//    test
    {
        ll n; cin >> n;
        ad(a, n);
        for (ll i = n - 1; i >= 0; i--)
        {
            for (ll j = i; j < n; j++)
            {
                if (i == j)
                    dp[i][j] = a[i];
                else
                    dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    return 0;
}