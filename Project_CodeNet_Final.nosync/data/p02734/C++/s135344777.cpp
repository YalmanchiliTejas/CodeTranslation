#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */


const lint mod = MOD9;
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
    constexpr mint& operator/(const mint& a) const{
        mint res(*this);
        return res/=a;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x; return os;
    }
};

mint dp[3005][3005][2];

int main(){
    int n, s; cin >> n >> s;
    rep(i, n){
        dp[i][0][0] = (i+1)*(i+2)/2 - i - 1;
        dp[i][0][1] = i+2;
    }

    rep(i, n){
        int a; cin >> a;
        if(i == 0){
            dp[0][a][0] = 1;
            dp[0][a][1] = 1;
        }
        else{
            repn(w, s){
                dp[i][w][0] = dp[i-1][w][0] + dp[i-1][w][1];
                dp[i][w][1] = dp[i-1][w][1];
                if(w >= a) dp[i][w][1] += dp[i-1][w-a][1];
            }
        }
    }

    out(dp[n-1][s][0] + dp[n-1][s][1]);
}