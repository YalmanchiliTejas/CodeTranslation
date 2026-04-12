#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pa pair<int, int>
#define pal pair<long long, long long>
#define pali pair<long long, int>
#define pad pair<double, double>
#define pb push_back
#define mp make_pair
#define COUT(v)                              \
    for (int64_t i = 0; i < (v).size(); ++i) \
    {                                        \
        cout << v.at(i) << endl;             \
    }
#define REP(i, n) for (int64_t i = 0; i < n; ++i)
#define FOR(i, r, n) for (int64_t i = (r); i < n; ++i)
#define VIN(v)                               \
    for (int64_t i = 0; i < (v).size(); ++i) \
    {                                        \
        cin >> (v).at(i);                    \
    }

typedef vector<bool> bvec;
typedef vector<int> ivec;
typedef vector<long long> lvec;
typedef vector<double> dvec;
typedef vector<pa> pavec;
typedef vector<pali> palivec;
typedef vector<pal> palvec;

typedef vector<vector<bool> > bmat;
typedef vector<vector<int> > imat;
typedef vector<vector<long long> > lmat;

typedef vector<string> svec;
typedef vector<vector<string>> smat;
const ll infll = (1LL << 60) - 1;
const int inf = (1 << 30) - 1;
const int MOD = 1000000007;

ll gcd(ll x, ll y)
{
    ll r = x % y;
    if (r == 0)
        return y;
    else
        return gcd(y, r);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

lvec mfactor(ll n)
{
    bvec ip(n, true);
    lvec mf(n, -1);
    ip[0] = false;
    ip[1] = false;
    mf[0] = 0;
    mf[1] = 1;
    REP(i, n)
    {
        if (ip[i])
        {
            mf[i] = i;
            for (ll j = i * i; j < n; j += i)
            {
                ip[j] = false;
                if (mf[j] == -1)
                    mf[j] = i;
            }
        }
    }
    return mf;
}

palivec get_prime(ll n, const lvec &mf)
{
    palivec plist;
    while (n != 1)
    {
        int cnt = 0;
        ll m = mf[n];
        while (mf[n] == m)
        {
            cnt++;
            n /= m;
        }
        plist.pb(pali(m, cnt));
    }
    return plist;
}

void COMinit(int m, lvec &fac, lvec &finv)
{
    lvec inv(m);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < m; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll pow_mod(ll a, ll n)
{
    ll x = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            x = x * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return x;
}
ll COM(int n, int k, const lvec &fac, const lvec &finv)
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

ll P(ll n, ll m)
{
    ll s = 1;
    ll cnt = n;
    REP(i, n - m)
    {
        s *= cnt % MOD;
        s %= MOD;
        --cnt;
    }
    return s;
}

ll delta(const lvec &x, ll p, int d)
{
    ll s = 0;
    REP(i, x.size())
    {
        s += -2 * (x[i] - p) * d + d * d;
    }
    return s;
}

ll delta(const lvec &x, ll p)
{
    ll s = 0;
    REP(i, x.size())
    s += (x[i] - p) * (x[i] - p);
    return s;
}

ll find(const lvec &x, ll p)
{
    ll mm = 1e5 + 1;
    ll res = x[0];
    REP(i, x.size())
    {
        if (abs(p - x[i]) < mm)
        {
            res = x[i];
            mm = abs(p - x[i]);
        }
    }
    return res;
}

bool check(int x, int y, const pavec &qpos){

    for (auto &v: qpos){
        if(v.first==x && v.second==y) continue;
        if(v.first==x) return true;
        if(v.second==y) return true;
        if(abs(v.first-x) == abs(v.second-y)) return true;
    }
    return false;

}
bool dfs(int x, int n, int d, pavec &qpos, const ivec &hind, const ivec &wind){
    if(x==d) {
        return true;
    }

    for (int i=0; i<n; i++){
        if(!check(hind[x], wind[i], qpos)){
            qpos.pb(pa(hind[x], wind[i]));
            if(dfs(x+1, n, d, qpos, hind, wind)) return true;
            else qpos.pop_back();
        }
    }
    return false;
}

void fac(int a, int b, bvec &fmap){
        for (int i=2; i<b; i++){
            if(fmap[i]) continue;
            else if(a%i==0) {
                fmap[i] = true;
                int n=a/i, x=i;
                while(n>=i){
                    n/=i;
                    x+=i;
                    fmap[x]=true;
                }
            }
        }
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int na=0, nb=0;
    for (auto v: s){
        if (v=='A') ++na;
        else ++nb;
    }
    if(na && nb) cout <<"Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
