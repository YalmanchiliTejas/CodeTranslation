#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;

static const int  MAX_INT = std::numeric_limits<int>::max();
static const long MAX_LONG = std::numeric_limits<long>::max();
static const ll   MAX_LL = std::numeric_limits<long long>::max();

#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

///////////////////////////////////////////////////
// ------------------- utils ------------------- //
///////////////////////////////////////////////////
// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
struct mint {
    static const int mod = 1000000007;
    long long x; // typedef long long ll;
    mint(long long x = 0) :x((x%mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
std::istream& operator>>(std::istream& is, mint& a) { return is >> a.x; }
std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x; }

///////////////////////////////////////////////////
// ------------------- main -------------------- //
///////////////////////////////////////////////////
void Main() {
    //ll N; cin >> N;
    //vector<ll> A(N, 0), Cum(N,0);
    //rep(i, N) cin >> A[i];

    //Cum[0] = A[0];
    //for (int i = 1; i < N; ++i) Cum[i] = (Cum[i - 1] + A[i]) % MOD;
    //
    //ll sum = 0;
    //rep(i, N - 1) {
    //    ll thisSum = (Cum[N - 1] - Cum[i]) % MOD;
    //    if (thisSum < 0) thisSum += MOD;
    //    sum += (A[i] * thisSum);
    //    sum %= MOD;
    //}
    //cout << sum << endl;

    ll N; cin >> N;
    vector<mint> A(N, 0), Cum(N, 0);
    rep(i, N) cin >> A[i];

    Cum[0] = A[0];
    for (int i = 1; i < N; ++i) Cum[i] = (Cum[i - 1] + A[i]);

    mint sum(0);
    rep(i, N - 1) {
        mint thisCum = Cum[N - 1] - Cum[i];
        sum += (A[i] * thisCum);
    }
    cout << sum << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);
    Main();

    double tmp;
    cin >> tmp;

    return 0;
}
