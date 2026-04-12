#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

const int mod = 1e9+7;
struct mint {
    ll x;
    mint (ll x = 0) : x((x%mod+mod)%mod) {}
    mint operator -() const {return mint(-x);}
    mint& operator +=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator -=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator *=(const mint a) {(x *= a.x) %= mod; return *this;}
    mint operator +(const mint a) const {return mint(*this) += a;}
    mint operator -(const mint a) const {return mint(*this) -= a;}
    mint operator *(const mint a) const {return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const {return pow(mod-2);}
    mint operator /=(const mint a) {return *this *= a.inv();}
    mint operator /(const mint a) {return mint(*this) /= a;}
};
istream& operator >>(istream &is, const mint &a) {return is >> a.x;}
ostream& operator <<(ostream &os, const mint &a) {return os << a.x;}

mint dp[10005][2][105];

int main() {
    string s; cin >> s;
    int n = s.size();
    int d; cin >> d;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,2)rep(k,d)rep(l,10) {
        int n_j = j; int n_k = (k+l)%d; int n_i = i+1;
        if (j == 0) {
            if (l > s[i]-'0') continue;
            if (l < s[i]-'0') n_j = 1;
        }
        dp[n_i][n_j][n_k] += dp[i][j][k];
    }
    cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
}