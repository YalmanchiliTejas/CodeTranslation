// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }

template<int MOD> struct modint {
    long long val;

    constexpr modint(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr modint operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    
    constexpr int getmod() { return MOD; }
    constexpr modint operator + (const modint& r) const noexcept { return modint(*this) += r; }
    constexpr modint operator - (const modint& r) const noexcept { return modint(*this) -= r; }
    constexpr modint operator * (const modint& r) const noexcept { return modint(*this) *= r; }
    constexpr modint operator / (const modint& r) const noexcept { return modint(*this) /= r; }
    constexpr modint& operator += (const modint& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator -= (const modint& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr modint& operator *= (const modint& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr modint& operator /= (const modint& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const modint& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const modint& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const modint<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, modint<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr modint<MOD> modpow(const modint<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = modint<MOD>;
typedef vector<mint> mvec;
typedef vector<vector<mint>> mvvec;

int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int lcm(int x, int y) { return x/gcd(x, y)*y; }
int mod_pow(int x, int y) { int res = 1; while (y > 0) { if (y & 1) { res = res * x % MOD; } x = x * x % MOD; y >>= 1; } return res; }
int comb(int n, int k) { k = min(k, n - k); int nnn = 1; for (int i = n - k + 1; i <= n; i++) { nnn *= i; nnn %= MOD; } int kkk = 1; for (int i = 1; i <= k; i++) { kkk *= i; kkk %= MOD; } return (nnn * mod_pow(kkk, MOD - 2)) % MOD; }
int to_int(string s) { int n = s.size(); int ans = 0; for (int i = 0; i < n; i++) { ans = ((ans * 10) + (s[i] - '0')) % MOD; } return ans; }
int DisitSum(int x){ int ret=0; while(x){ ret++;x/=10;} return ret; }
bool is_prime(int n) { for(int i = 2; i*i <= n; i++) { if (n % i == 0) return false; } return n != 1; }
int extgcd(int a, int b, int& x, int& y) { // ax+by = gcd(a,b) >> gcd(a,b)
    int d = a;
    if(d != 0) { d = extgcd(b, a%b, y, x); y -= (a/b)*x; }
    else { x = 1, y = 0; }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,m,k;
    cin>>n>>m>>k;
    int nm=comb(n*m-2,k-2);
    mint ans=0;
    rep(i,m){
        ans+=((nm*(n*n)%MOD)%MOD)*((m-i)*(m-i-1)/2%MOD);
    }
    rep(i,n){
        ans+=((nm*(m*m)%MOD)%MOD)*((n-i)*(n-i-1)/2%MOD);
    }
    cout<<ans<<endl;
}
