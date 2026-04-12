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

string k;
ll d;
ll dp[100005][102][2];


ll f(ll index, ll sum, ll tight)
{
    if (index == k.size())
        return sum == 0;
    if (dp[index][sum][tight] != -1 && tight != 1)
        return dp[index][sum][tight];
    ll ans = 0;
    ll n = tight ? k[index] - '0' : 9;
    for (ll i = 0; i <= n; i++)
    {
        ll new_tight = (k[index] - '0' == i) ? tight : 0;
        ans += f(index + 1, (sum + i) % d, new_tight);
        ans %= p7;
    }
    dp[index][sum][tight] = ans;
    return ans;
}


int32_t main()
{
    ss99();
//    test
    {
        cin >> k >> d;
        memset(dp, -1, sizeof(dp));
        ll ans = f(0, 0, 1);
        cout << (ans - 1 + p7) % p7 << endl;
    }
    return 0;
}