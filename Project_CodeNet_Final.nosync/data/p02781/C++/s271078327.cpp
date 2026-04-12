#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1e9 + 7;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template <int MOD> struct Fp {
    long long val;

    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if(val < 0)
            v += MOD;
    }

    constexpr int getmod() { return MOD; }

    constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }

    constexpr Fp operator+(const Fp &r) const noexcept {
        return Fp(*this) += r;
    }

    constexpr Fp operator-(const Fp &r) const noexcept {
        return Fp(*this) -= r;
    }

    constexpr Fp operator*(const Fp &r) const noexcept {
        return Fp(*this) *= r;
    }

    constexpr Fp operator/(const Fp &r) const noexcept {
        return Fp(*this) /= r;
    }

    constexpr Fp &operator+=(const Fp &r) noexcept {
        val += r.val;
        if(val >= MOD)
            val = val % MOD;
        return *this;
    }

    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if(val < 0)
            val += MOD * ((-val + MOD - 1) / MOD);
        val = val % MOD;
        return *this;
    }

    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }

    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if(val < 0)
            val += MOD;
        return *this;
    }

    constexpr bool operator==(const Fp &r) const noexcept {
        return this->val == r.val;
    }

    constexpr bool operator!=(const Fp &r) const noexcept {
        return this->val != r.val;
    }

    friend constexpr ostream &operator<<(ostream &os,
                                         const Fp<MOD> &x) noexcept {
        return os << x.val;
    }

    friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept {
        return is >> x.val;
    }

    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if(n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if(n & 1)
            t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|

int ctoi (const char c){
  if ('0' <= c && c <= '9') return (c - '0');
  return -1;
}

int main(){
    string N;
    int K;
    cin >> N;
    cin >> K;
    int L = N.length();
    static ll dp1[102][5] = {};
    static ll dp2[102][5] = {};

    REP(i,L){
        REP(d,K+1){
            ll num = ctoi(N[i]);
            if (i == 0){
                dp2[0][0] = 1;
                dp2[0][1] = (ll)ctoi(N[0]) - 1;
                dp1[0][1] = 1;
            }else{
                if (d >= 1){
                    if (num > 0) dp1[i][d] = dp1[i-1][d-1];
                    else dp1[i][d] = dp1[i-1][d];
                    
                    dp2[i][d] = dp2[i-1][d] + 9 * dp2[i-1][d-1];
                    dp2[i][d] += max(0LL,(num - 1)) * dp1[i-1][d-1];
                    if (num > 0) dp2[i][d] += dp1[i-1][d];
                }else{
                    // d = 0
                    if (num > 0) dp1[i][d] = 0;
                    else dp1[i][d] = dp1[i-1][d];
                    
                    dp2[i][d] = dp2[i-1][d];
                    if (num > 0) dp2[i][d] += dp1[i-1][d];
                }

            }
        }
    }

    cout << dp1[L-1][K] + dp2[L-1][K] << endl;
}