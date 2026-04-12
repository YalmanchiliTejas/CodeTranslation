#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 998244353;
const long double EPS = 1e-8;

namespace mod {
    long long pow(long long a, long long x, long long p) {
        long long res = 1;
        while(x > 0) {
            if( x % 2 != 0) {
                res = (res * a) % p;
            }
            a = (a * a) % p;
            x /= 2;
        }
        return res;
    }

    long long inverse(long long a, long long p) {
        //calculates the modular multiplicative of a mod m.
        //(assuming p is prime).
        return pow(a, p-2, p);
    }

    long long factorial(long long a, long long p) {
        long long fact = 1;
        for (long long i=2; i<=a; i++) {
            fact *= i;
            fact %= p;
        }
        return fact;
    }

    template <long long MOD>
    struct Int {
        long long x;
        Int(long long x = 0) : x((x % MOD + MOD) % MOD){}
        Int operator-() const { return Int<MOD>(-x);}
        Int& operator+=(const Int<MOD> a) {
            if ((x += a.x) >= MOD) x -= MOD;
            return *this;
        }
        Int& operator-=(const Int<MOD> a) {
            if ((x += MOD-a.x) >= MOD) x -= MOD;
            return *this;
        }
        Int& operator*=(const Int<MOD> a) {
            (x *= a.x) %= MOD; return *this;
        }
        Int operator+(const Int<MOD> a) const { return Int<MOD>(*this) += a;}
        Int operator-(const Int<MOD> a) const { return Int<MOD>(*this) -= a;}
        Int operator*(const Int<MOD> a) const { return Int<MOD>(*this) *= a;}
        Int pow(long long t) const {
            if (!t) return 1;
            Int<MOD> a = pow(t >> 1);
            a *= a;
            if (t&1) a *= *this;
            return a;
        }

        Int inv() const { return pow(MOD - 2);}
        Int& operator/=(const Int<MOD> a) { return *this *= a.inv();}
        Int operator/(const Int<MOD> a) const { return Int<MOD>(*this) /= a;}
    };
}
std::istream& operator>>(std::istream& is, const mod::Int<MOD>& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mod::Int<MOD>& a) { return os << a.x;}

void solve(long long N, long long S, std::vector<long long> A){
    vector<vector<vector<mod::Int<MOD>>>> dp(N+1, vector<vector<mod::Int<MOD>>>(S+1, vector<mod::Int<MOD>>(3)));
    dp[0][0][0] = 1;
    rep(i,0,N) rep(s,0,S+1) {
        dp[i+1][s][0] += dp[i][s][0];
        dp[i+1][s][1] += dp[i][s][0] + dp[i][s][1];
        dp[i+1][s][2] += dp[i][s][0] + dp[i][s][1] + dp[i][s][2];
        if (s + A[i] > S) continue;
        dp[i+1][s + A[i]][1] += dp[i][s][0] + dp[i][s][1];
        dp[i+1][s + A[i]][2] += dp[i][s][0] + dp[i][s][1];
    }
    cout << dp[N][S][2] << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    long long S;
    scanf("%lld",&S);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}
