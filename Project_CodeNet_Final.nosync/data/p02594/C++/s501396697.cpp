#include<bits/stdc++.h>
using namespace std;

#define fastio        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll            long long
#define fl            long double
#define pll           pair<ll,ll>
#define onebits(x)    __builtin_popcountll(x)
#define pb            push_back
#define mk            make_pair
#define endl          "\n"
#define ff            first
#define ss            second
#define mt            make_tuple
#define np            next_permutation
#define pi            3.141592653589793238
#define deb(x)        cerr<<#x<<' '<<'='<<' '<<x<<'\n'
#define vll           vector<ll>
#define vp            vector<pair<ll,ll>>
#define all(x)        x.begin(),x.end()
#define revpq         priority_queue <int, vector<int>, greater<int>>
#define ps(x,y)       fixed<<setprecision(y)<<x
const ll mod = 1e9 + 7;
const ll INF = 1e18;
ll power(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod % mod; a = a * a % mod;} return res;}
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll i, j, t, k , n , m, l;
    cin >> t;
    if (t >= 30)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}