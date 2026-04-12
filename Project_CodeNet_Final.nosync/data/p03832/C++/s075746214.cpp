#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
#include <functional>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<ll, ll> PL;
typedef vector<PL> vpl;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back
#define ALL(X) (X).begin(),(X).end()

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    sort(ALL(vec));
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

inline ll popcnt(ll x){return __builtin_popcountll((unsigned long long)x);};
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
//friend bool operator<(const stc& lhs, const stc& rhs){
//    return std::tie(lhs.l, lhs.r) < std::tie(rhs.l, rhs.r);
//}


const ll mod = 1e9+7;
template< int mod >
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inv();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    
    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
    
    static int get_mod() { return mod; }
};

using mint = ModInt<mod>;
typedef vector<mint> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;

const ll size = 300300; // ******** CHECK ME !!!!!!! ********
mint fact[size], finv[size];

mint nCk(ll n, ll k){
    if(n < k) return 0;
    return fact[n]*finv[k]*finv[n-k];
}

void prepare(){
    fact[0] = 1;
    rep(i, size-1) fact[i+1] = fact[i]*mint(i+1);
    finv[size-1] = fact[size-1].inv();
    for (ll i = size-1; i > 0; i--) {
        finv[i-1] = finv[i]*mint(i);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    vvm dp(N+2, vm(N+1, 0));
    dp[A][0] = 1;
    FOR(i, A, B+1){
        mint acc = 1;
        FOR(k, 1, C) acc *= nCk(k*i, i);
        FOR(k, C, D+1){
            if(k*i > N) break;
            acc *= nCk(k*i, i);
            rep(j, N+1){
                if(j-k*i >= 0){
                    dp[i+1][j] += dp[i][j-k*i] * nCk(N-(j-k*i), k*i) * acc * finv[k];
                }
            }
        }
        rep(j, N+1) dp[i+1][j] += dp[i][j];
    }
    cout << dp[B+1][N] << endstr;
    return 0;
}
