#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <random>
#include <ctime>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ld long double
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast_io cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ld eps = (ld)1 / 1e6;
ll inf = LLONG_MAX, mod1 = 1e9 + 7, mod2 = 998244353;
ll sqr(ll a) { return a * a; }
ll qb(ll a) { return a * a * a; }
ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll binpow(ll a, ll b, ll mod) { return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod : sqr(binpow(a, b / 2, mod)) % mod) : 1; }
ll binmult(ll a, ll b, ll mod) { return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod : (2 * binmult(a, b / 2, mod)) % mod) : 0; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll a[200001];

int main()
{
    fast_io;
    ll n, i, t, sum = 0, s = 0;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i], sum += a[i], sum %= mod1;
    for (i = 1; i < n; i++)
    {
        sum -= a[i];
        if (sum < 0) sum += mod1;
        t = sum * a[i];
        t %= mod1;
        s += t;
        s %= mod1;
    }
    cout << s;
    return 0;
}