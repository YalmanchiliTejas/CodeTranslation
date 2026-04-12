#include <bits/stdc++.h>
#include <climits>

using namespace std;

template<class T>
using V = vector<T>;
template<class T>
using VV = V<V<T>>;

using ld = long double;
#define ll long long
using ull = unsigned ll;
using PLL = pair<ll, ll>;
using VLL = V<ll>;
using VB = V<bool>;
using VVB = VV<bool>;
using VVLL = VV<ll>;
using Gr = VVLL;
using MLL = map<ll, ll>;
#define UMLL unordered_map<ll, ll, custom_hash>
//typedef __int128 int128;
//typedef __float128 double128;

#define fast ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

#define INF LLONG_MAX
#define MINF LLONG_MIN

#define R &
#define CR const R

#define FORI(i, a, b) for(ll i = a, max##i = b; i < max##i; ++i)
#define FOR(i, n) FORI(i, 0, n)
#define RFORI(i, a, b) for(ll i = a, min##i = b; i >= min##i; --i)
#define RFOR(i, n) RFORI(i, n, 0)
#define FORA(i, a) for(auto i : a)
#define FORAR(i, a) for(auto R i : a)
#define FORACR(i, a) for(auto CR i : a)
#define ALL(obj) begin(obj), end(obj)
#define Count(q) while(q--)
#define OK cerr << "OK\n";

#define mp make_pair
#define pb push_back

//#define DEBUG

template<class T>
T sqr(T x)
{
    return x * x;
}

void YES(bool g, ostream R os, bool upper = false)
{
    if(g)
        if(upper)
            os << "YES";
        else
            os << "Yes";
    else
        if(upper)
            os << "NO";
        else
            os << "No";

    os << "\n";
}

template<class T>
ll cast(T CR t)
{
    return static_cast<ll>(t);
}

template<class T>
void show(T CR t, ostream R os = cerr)
{
    FORACR(i, t)
        os << i << " ";
    os << "\n";
}

constexpr ll MOD = 1e9 + 7;
//constexpr ll len = 2 * ('z' - 'a' + 1);
//constexpr ld eps = 1e-9;

//constexpr ld unreal = -1e9;

constexpr ld PI = atanl(1.0L) * 4;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(istream R is, ostream R os)
{
    ll n;
    is >> n;

    VLL a(n);
    FORAR(i, a)
        is >> i;

    ll sum = 0;
    FORACR(i, a)
        sum = (sum + i) % MOD;

    ll ans = 0;
    FORACR(i, a)
    {
        sum = (sum - i + MOD) % MOD;
        ans = (ans + i * sum) % MOD;
    }

    os << ans << "\n";
}

int main()
{
    fast
    ll q = 1;
    //cin >> q;
    cout << setprecision(999);
    Count(q)
        solve(cin, cout);
}
