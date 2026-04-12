// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

// ModInt begin

using ll = long long;
template<ll mod>
struct ModInt {
    ll v;
    ll mod_pow(ll x, ll n) const {
        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;
    }
    ModInt(ll a = 0) : v(a >= mod ? a % mod : a) {}
    ModInt operator+ ( const ModInt& b ) const {
        return (v + b.v >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));
    }
    ModInt operator- () const {
        return ModInt(-v);
    }
    ModInt operator- ( const ModInt& b ) const {
        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));
    }
    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}
    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2)) % mod;}
    
    bool operator== ( const ModInt &b ) const {return v == b.v;}
    ModInt& operator+= ( const ModInt &b ) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }
    ModInt& operator-= ( const ModInt &b ) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }
    ModInt& operator*= ( const ModInt &b ) {
        (v *= b.v) %= mod;
        return *this;
    }
    ModInt& operator/= ( const ModInt &b ) {
        (v *= mod_pow(b.v, mod-2)) %= mod;
        return *this;
    }
    ModInt pow(ll x) { return ModInt(mod_pow(v, x)); }
    // operator int() const { return int(v); }
    // operator long long int() const { return v; }
};

template<ll mod>
ostream& operator<< (ostream& out, ModInt<mod> a) {return out << a.v;}
template<ll mod>
istream& operator>> (istream& in, ModInt<mod>& a) {
    in >> a.v;
    return in;
}

// ModInt end

// 各種組み合わせを求めるライブラリ
template <typename NumType>
struct Combination {
    int LIMIT;
    vector<NumType> fact_, finv_;

    Combination() {}
    Combination(int LIMIT_) : LIMIT(LIMIT_), fact_(LIMIT+1), finv_(LIMIT+1) {
        fact_[0] = finv_[LIMIT] = NumType(1);
        for(int i=1; i<=LIMIT; i++) {
            fact_[i] = fact_[i-1] * NumType(i);
        }
        
        finv_[LIMIT] /= fact_[LIMIT];
        for(int i=LIMIT-1; i>=0; i--) {
            finv_[i] = finv_[i+1] * NumType(i+1);
        }
    }

    inline NumType fact(int k) const { return fact_[k]; }
    inline NumType finv(int k) const { return finv_[k]; }
    NumType P(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r];
    }
    NumType C(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r] * finv_[r];
    }
    // 重複組み合わせ
    NumType H(int n, int r) const {
        if(n < 0 or r < 0) return NumType(0);
        return r == 0 ? NumType(1) : C(n + r - 1, r);
    }
    // ベル数 (区別できる n 個のボールを区別できない k 個以下の箱に分割)
    // B(n, n) := n 個のボールを任意個のグループに分割する場合の数
    NumType B(int n, int k) const {
        if(n == 0) return NumType(1);
        k = min(n, k);
        NumType ret(0);
        vector<NumType> pref(k + 1); pref[0] = NumType(1);
        for(int i=1; i<=k; i++) {
            if(i & 1) pref[i] = pref[i-1] - finv_[i];
            else pref[i] = pref[i-1] + finv_[i];
        }
        for(int i=1; i<=k; i++) {
            // 累乗が必要なので適宜書き換える？
            // ModInt 使うならこれでいい
            ret += NumType(i).pow(n) * finv_[i] * pref[k-i];
        }
        return ret;
    }
    // スターリング数 (区別できる n 個のボールを区別できない k 個の箱に分割)
    NumType S(int n, int k) const {
        if(n < k) return NumType(0);
        NumType ans(0);
        for(int i=0; i<=k; i++) {
            NumType val = C(k, i) * NumType(i).pow(n);
            if((k - i) % 2) ans -= val;
            else ans += val;
        }
        return ans * finv_[k];
    }
};

// P(n, k) := n の k 分割 (k 個の 0 以上の整数の和)
template <typename NumType, int LIMIT = 3010>
struct Partition {
    vector< vector<NumType> > dp;
    Partition() : dp(LIMIT, vector<NumType>(LIMIT)) {
        for(int k=0; k<LIMIT; k++) dp[0][k] = NumType(1);
        for(int i=1; i<LIMIT; i++) {
            for(int j=1; j<LIMIT; j++) {
                dp[i][j] += dp[i][j-1];
                if(i-j >= 0) dp[i][j] += dp[i-j][j];
            }
        }
    }
    inline NumType get(int n, int k) {
        if(n < 0 or k < 0) return NumType(0);
        return dp[n][k];
    }
};

signed main() {
    using mint = ModInt<MOD>;
    Combination<mint> comb(200010);

    int N, M, K; cin >> N >> M >> K;
    mint c = comb.C(N*M-2, K-2);
    cerr << "c = " << c << endl;
    
    mint sum = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            sum += i + j;
        }
    }

    mint coeff = 0, cur = sum;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            coeff += cur;
            cur += mint((j + 1) * N);
            cur -= mint((M - j - 1) * N);
        }
        sum += mint((i + 1) * M);
        sum -= mint((N - i - 1) * M);
        cur = sum;
    }
    coeff /= mint(2);
    
    cout << c * coeff << endl;
    return 0;
}
