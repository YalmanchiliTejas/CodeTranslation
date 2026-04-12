#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, sta, n) for (int i = sta; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define per1(i, n) for (int i = n; i >= 1; i--)
#define Rep1(i, sta, n) for (int i = sta; i <= n; i++)
#define all(v) (v).begin(), (v).end()
const ll mod = 1000000007;
const ll INF = mod * mod;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll qp(ll a, ll b, int mo)
{
    int ans = 1;
    do
    {
        if (b & 1)
            ans = 1ll * ans * a % mo;
        a = 1ll * a * a % mo;
    } while (b >>= 1);
    return ans;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } // 最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     // 最小公倍数
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
    os << "deq[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
    os << "(" << pa.first << "," << pa.second << ")";
    return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}
template <typename T>
void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args>
void ndarray(vector<T> &vec, int len, Args... args)
{
    vec.resize(len);
    for (auto &v : vec)
        ndarray(v, args...);
}
template <typename T>
bool chmax(T &m, const T q)
{
    if (m < q)
    {
        m = q;
        return true;
    }
    else
        return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
    if (q < m)
    {
        m = q;
        return true;
    }
    else
        return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator<(const pair<T1, T2> l, const pair<T1, T2> r) { return (l.first < r.first); }
template <typename T1, typename T2>
pair<T1, T2> operator>(const pair<T1, T2> l, const pair<T1, T2> r) { return (l.first > r.first); }

struct mint {
    ll n;
    mint(ll a = 0) {n = a % mod;}
    mint& operator+=(mint a) {n += a.n; n %= mod; return *this;}
    mint& operator-=(mint a) {n += mod; n -= a.n; n %= mod; return *this;}
    mint& operator*=(mint a) {n *= a.n; n %= mod; return *this;}
    mint& operator%=(mint a) {n %= a.n; return *this;}
    mint& operator++() {n++;n %= mod; return *this;}
    mint& operator--() {n += mod; n--; n %= mod; return *this;}
};
mint operator+(mint a, mint b) {a += b; return a;}
mint operator-(mint a, mint b) {a -= b; return a;}
mint operator*(mint a, mint b) {a *= b; return a;}

mint factMod(ll n) {
    if (n == 0)
    {
        return 1;
    }
    mint ans = 1;
    while (n > 1) {
        ans *= n;
        n--;
    }
    return ans;
}

mint powMod(mint x, ll y) {
    if (x.n <= 1)
    {
        return x;
    }
    if (y == 0)
    {
        return 1;
    }
    else if (y == 1)
    {
        return x;
    }
    else if (y % 2 == 0)
    {
        mint tmp = powMod(x, y / 2);
        return tmp * tmp;
    }
    else
    {
        mint tmp = powMod(x, y / 2);
        return tmp * tmp * x;
    }
}

// modは素数
mint modinv(mint n)
{
    return powMod(n, mod - 2);
}

// modは素数でなくてもいい
long long modinv(long long a, long long m = mod) {
    long long b = m, u = 1, v = 0;
    while(b){
        long long t = a / b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

vector<ll> invtbl;
void preCalcInv(ll up)
{
    invtbl.resize(up + 1);
    invtbl[1] = 1;
    for(ll a=2; a<=up; a++)
    {
        invtbl[a] = mod - invtbl[mod % a] * (mod / a) % mod;
    }
}

mint operator/(mint a, mint b)
{
    if (b.n < invtbl.size())
    {
        a *= invtbl[b.n];
    }
    else
    {
        a *= modinv(b);
    }
    return a;
}
mint& operator/=(mint& a, mint b)
{
    a = a / b;
    return a;
}


mint nCrMod(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
    {
        return 0;
    }
    r = min(r, n - r);
    mint a = 1;
    for(ll i= n-r+1; i<=n; i++)
    {
        a *= i;
    }

    a /= factMod(r);
    return a;
}

mint nHrMod(ll n, ll r)
{
    return nCrMod(n + r - 1, r);
}

template<class T>
constexpr auto modK_belowN(T k, T MOD, T n)
{
    return (n + MOD - k - 1) / MOD;
}


void solve(){
    ll N,M,K; cin >> N >> M >> K;

    mint res = 0;
    mint c = nCrMod(N*M-2, K-2);

    rep(i,N){
        rep(j,M){
            if(i==0&&j==0) continue;
            mint val = i+j;
            if(i>0&&j>0) val *= 2;
            val *= (N-i); 
            val *= (M-j);
            val *= c; 
            res += val;
        }
    }

    cout << res.n << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    std::cout << fixed << setprecision(10);
    solve();
    return 0;
}
