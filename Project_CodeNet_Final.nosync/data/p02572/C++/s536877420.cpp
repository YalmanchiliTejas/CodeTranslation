// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//========================TypeDefs===================================

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

//=========================MACROS====================================

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define acc(v) accumulate(all(v), 0)
#define fi first
#define se second

#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvll vector<vll>

#define mli map<ll, int>
#define mll map<ll, ll>

#define forz(i, n) for (int i = 0; i < n; i++)
#define fora(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rfora(i, n, m) for (int i = n; i >= m; i--)

#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define clz(n) __builtin_clz(n)
#define clzll(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)

#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))

#define lb lower_bound
#define ub upper_bound
#define er equal_range

#define findnot find_first_not_of

#define maxe *max_element
#define mine *min_element

#define MOD 1000000007
#define MOD2 998244353
#define PI 3.1415926535897932384
#define INF LLONG_MAX

#define gcd __gcd
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define P0(a) cout << a << " "
#define P1(a) cout << a << endl
#define P2(a, b) cout << a << " " << b << endl
#define P3(a, b, c) cout << a << " " << b << " " << c << endl
#define P4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>

#define ofk order_of_key
#define fbo find_by_order
//member functions :
//1. order_of_key(k) : number of elements sbtriectly lesser than k
//2. find_by_order(k) : k-th element in the set

//==============================FUNCTIONS===========================================

auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
void run_time()
{
    cout << endl;
    cout << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;
}

inline ll power(ll x, ll y, ll p = MOD)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

inline ll modadd(ll a, ll b, ll m = MOD)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

inline ll modmul(ll a, ll b, ll m = MOD)
{
    return ((a % m) * (b % m)) % m;
}

inline ll modi(ll a, ll m = MOD) { return power(a, m - 2, m); }

long long int inverse(long long int i, ll m = MOD)
{
    if (i == 1)
        return 1;
    return (m - ((m / i) * inverse(m % i)) % m + m) % m;
}

//================================CODE=============================================

int main()
{
    fastio;
    ll n,ans=0;
    cin >> n;
    vll v(n), vsum(n);

    fora(i, 0, n)
    {
        cin >> v[i];
        if (i == 0)
            vsum[i] = v[i];
        else
            vsum[i] = vsum[i - 1] + v[i];
    }

    fora(i,1,n)
    {
        ans+= (((vsum[i]-v[i])%MOD)*(v[i]%MOD))%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    //run_time();
    return 0;
}