#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

// 自動でmodを取ってくれる整数型
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
// const int mod = 998244353;
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
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint f(int n){ // 2のn乗
    if(n==0) return 1;
    mint x=f(n/2);
    x*=x;
    if(n%2==1) x*=2;
    return x;
}

// a^n mod を計算する
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//////////////////////////
int main(){
    string k;
    ll d;
    cin>>k>>d;
    int n=k.size();
    vector<vector<mint>> dp(d, vector<mint>(2,0));
    dp[0][0]=0;
    dp[0][1]=1;
    rep(i,n){
        ll c=k[i]-'0';
        vector<vector<mint>> dpt(d, vector<mint>(2,0));
        rep(j,d){
            rep(l,10){
                if(l<c){
                    dpt[(j+l)%d][0]+=dp[j][0];
                    dpt[(j+l)%d][0]+=dp[j][1];
                }
                else if(l==c){
                    dpt[(j+l)%d][0]+=dp[j][0];
                    dpt[(j+l)%d][1]+=dp[j][1];
                }
                else dpt[(j+l)%d][0]+=dp[j][0];
            }
        }
        dp=dpt;
    }
  cout<<dp[0][1]+dp[0][0]-1<<endl;
}
