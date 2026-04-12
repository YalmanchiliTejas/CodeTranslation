//const int N = 1e3+5;
//ll dp[N][N];
//void _(){
//    dp[0][0] = 1;
//    int n,a,b,c,d;
//    cin >> n >> a >> b >> c >> d;
//    Factorial f(n);
//    rep(sz_max,1,n){
//        rep(i,0,n){
//            for(int take = 0; take*sz_max <= i; ++take){
//                if(take != 0){
//                    if(take < c || take > d) continue;
//                    if(sz_max < a || sz_max > b) continue;
//                }
//                dp[i][sz_max] = (dp[i][sz_max]+dp[i-take*sz_max][sz_max-1]
//                    *f.comb(i,take*sz_max)%MOD
//                    *f.fact[take*sz_max]%MOD
//                    *ipow(f.ifact[sz_max],take)%MOD
//                    *f.ifact[take]
//                    )%MOD;
//            }
//        }
//    }
//    print(dp[n][n]);
//}
//
#include <iomanip>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define REP_INT(i,l,r) for(int i = l; i <= r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll MOD = 1e9 + 7;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
T1 void print(T x, string end = "\n"){
    cout << x << end;
}
T1 T ext_euclid(T a, T b, T c, T d){
    if(c == T(0))
        return b;
    return ext_euclid(c, d, a % c, b - a / c * d);
}
T1 T mod_inverse(T x, T mod = T(MOD)){
    return (ext_euclid(mod, T(0), x, T(1)) + mod) % mod;
}
ll mod_inverse(int x, ll mod = MOD){
    return mod_inverse<ll>(x,mod);
}
ll ipow(ll x, ll p, ll mod = MOD){
    if(abs(x) >= mod)
        x %= mod;
    if(x < 0)
        x += mod;
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    return ipow(x * x % mod, p / 2, mod) * ipow(x, p % 2, mod) % mod;
}
struct Factorial{
    vl fact,ifact;
    ll comb(ll n, ll m){
        assert(n >= m);
        assert(n < sz(fact));
        return fact[n]*ifact[m]%MOD*ifact[n-m]%MOD;
    }
    Factorial(int n){
        fact.resize(n+1);
        ifact.resize(n+1);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i)
            fact[i] = fact[i-1]*i%MOD;
        ifact[n] = mod_inverse(fact[n]);
        for(int i = n-1; i >= 0; --i)
            ifact[i] = (i+1)*ifact[i+1]%MOD;
    }
};
const int N = 1e3+5;
ll dp[N][N];
void _(){
    dp[0][0] = 1;
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    Factorial f(n);
    rep(sz_max,1,n){
        rep(i,0,n){
            for(int take = 0; take*sz_max <= i; ++take){
                if(take != 0){
                    if(take < c || take > d) continue;
                    if(sz_max < a || sz_max > b) continue;
                }
                dp[i][sz_max] = (dp[i][sz_max]+dp[i-take*sz_max][sz_max-1]
                    *f.comb(i,take*sz_max)%MOD
                    *f.fact[take*sz_max]%MOD
                    *ipow(f.ifact[sz_max],take)%MOD
                    *f.ifact[take]
                    )%MOD;
            }
        }
    }
    print(dp[n][n]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        _();
}
