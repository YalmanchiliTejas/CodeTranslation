#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<typename T> inline bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T &a,T b){if(b<a){a=b;return 1;}return 0;}
template<typename T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_vec(size_t a,Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a,make_vec<T>(ts...));}
template<typename T,typename U,typename... V>
typename enable_if<is_same<T,U>::value>::type fill_v(U &u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V>
typename enable_if<!is_same<T,U>::value>::type fill_v(U &u,const V... v){for(auto &e:u)fill_v<T>(e,v...);}

const int mod = 1000000007;

struct mint {
    long long x;
    mint(long long x=0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
bool operator==(const mint& a, const mint& b) { return a.x == b.x;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int d;
    cin >> d;
    int n = sz(s);
    auto dp = make_vec<mint>(n+1, d, 2);
    dp[0][0][0] = 1;
    rep(i, n) {
        rep(j, d) {
            rep(k, 2) {
                for (int x = 0; x <= (k ? 9 : s[i] - '0'); ++x) {
                    dp[i+1][(j+x)%d][k||x<s[i]-'0'] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = dp[n][0][0] + dp[n][0][1] - mint(1);
    cout << ans << endl;
}
