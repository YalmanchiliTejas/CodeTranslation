#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , "; logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

const lint mod = MOD;
class mint{
    public:
        long long x;

    constexpr mint(long long _x = 0) : x((_x%mod+mod)%mod) {}
    constexpr mint operator-() const{
        return mint(-x);
    }
    constexpr mint& operator+=(const mint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator-=(const mint& a){
        if((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator*=(const mint& a){
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint& a) const{
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint& a) const{
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint& a) const{
        mint res(*this);
        return res*=a;
    }
    constexpr mint pow(long long x) const{
        if(!x) return 1;
        mint a = pow(x>>1);
        a *= a;
        if(x&1) a *= *this;
        return a; 
    }
    constexpr mint inv() const{
        return pow(mod-2);
    }
    constexpr mint& operator/=(const mint& a){
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint& a) const{
        mint res(*this);
        return res/=a;
    }
    friend istream& operator>>(istream& is, mint& m){
        long long x; is >> x; m = x;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x; return os;
    }
};

int main(){
    int n; cin >> n;
    vector<mint> vec(n); rep(i,n) cin >> vec[i];

    mint ans = 0, sum = 0;
    rep(i,n) sum += vec[i];
    ans = sum * sum;

    mint prod = 0;
    rep(i,n) prod += vec[i]*vec[i];
    ans -= prod;
    ans /= 2;
    out(ans);
}