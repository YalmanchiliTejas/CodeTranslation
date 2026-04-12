#include <bits/stdc++.h>
// aya_seは起床のプロ
using namespace std;

//@ebi's definition

#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define rrep(i, a, n) for (int i = ((int)(n - 1)); i >= (int)(a); i--)
#define all(v) (v).begin(), (v).end()

using ll = long long;

struct Edge
{
    int to;
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<ll>>;

// xxpoxx's definition
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define RES(a, n) (a).resize(n)
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 2.0 * asin(1.0);
const ll INF = 1L << 60;
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MAX = 10000000;
/****** define constant end ********/

// aya_se's definition
vl fac, finv, inv;
void COMinit(ll N)
{
    fac.resize(N);
    finv.resize(N);
    inv.resize(N);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    cout << std::fixed << std::setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, p;
    cin >> t >> p;
    ll pite = 0;
    string now = "";
    REP(i, t.size())
    {
        if (t.substr(i, 1) == now && p.substr(pite, 1) != t.substr(i, 1))
        {
            cout << "no" << endl;
            return 0;
        }
        if (p.substr(pite, 1) != t.substr(i, 1))
        {
            continue;
        }
        now = t.substr(i, 1);
        pite++;
    }
    if (pite == p.size())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

