#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;

const ll mod = 998244353;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const { //値をt乗する
    if (!t) return 1; // t == 0
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this; //*thisは元の値(t乗する対象)
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[3050][3050][3];

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,s+1){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
            dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            if(j + a[i] <= s){
                dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1];
                dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1];
            }
        }
    }
    cout << dp[n][s][2].x << endl;
  
    return 0;
}