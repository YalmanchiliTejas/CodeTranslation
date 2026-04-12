#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<58);

template <unsigned long long mod > class modint{
public:
    ll x;
    constexpr modint(){x = 0;}
    constexpr modint(ll _x) : x((_x < 0 ? ((_x += (LLONG_MAX / mod) * mod) < 0 ? _x + (LLONG_MAX / mod) * mod : _x) : _x)%mod){}
    constexpr modint operator-(){
        return x == 0 ? 0 : mod - x;
    }
    constexpr modint& operator+=(const modint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr modint operator+(const modint& a) const{
        return modint(*this) += a;
    }
    constexpr modint& operator-=(const modint& a){
        if((x -= a.x) < 0) x += mod;
        return *this;
    }
    constexpr modint operator-(const modint& a) const{
        return modint(*this) -= a;
    }
    constexpr modint& operator*=(const modint& a){
        (x *= a.x)%=mod;
        return *this;
    }
    constexpr modint operator*(const modint& a) const{
        return modint(*this) *= a;
    }
    constexpr modint pow(unsigned long long pw) const{
        modint res(1), comp(*this);
        while(pw){
            if(pw&1) res *= comp;
            comp *= comp;
            pw >>= 1;
        }
        return res;
    }
    //以下、modが素数のときのみ
    constexpr modint inv() const{
        return modint(*this).pow(mod - 2);
    }
    constexpr modint& operator/=(const modint &a){
        (x *= a.inv().x)%=mod;
        return *this;
    }
    constexpr modint operator/(const modint &a) const{
        return modint(*this) /= a;
    }
};
#define mod1 998244353
#define mod2 1000000007
using mint = modint<mod2>;

ostream& operator<<(ostream& os, const mint& a){
    os << a.x;
    return os;
}
using vm = vector<mint>;

int main() {
    cin>>N;
    vec a(N);
    vm sum(N + 1);
    sum[0] = 0;
    rep(i,N){
        cin>>a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    mint res(0);
    rep(i,N) res += sum[i] * a[i];
    cout<<res<<endl;
}