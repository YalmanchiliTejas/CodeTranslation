#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define debugbit(x, n) cerr << #x << " = " << bitset<n>(x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define debugbit(x, n)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
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

void solve(long long N, std::vector<long long> A){
    ll sum = accumulate(all(A), 0LL) % MOD;
    mod::Int<MOD> answer = 0;
    rep(i,0,N) {
        answer += A[i] * sum;
        answer -= A[i] * A[i];
    }
    answer /= 2;
    cout << answer << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
