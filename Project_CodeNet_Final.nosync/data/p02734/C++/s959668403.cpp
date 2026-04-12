/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0;i < n;i++)
using ll = int64_t;

template<class T> void print(vector<T>& a){
    int sz = a.size();
    for(int i=0;i<sz;i++)cout<<a[i] << (i<sz-1?' ':'\n');
}

template<class T> bool chmin(T& a,T b){
    if(a > b){ a = b; return true; } return false;
}
template<class T> bool chmax(T& a,T b){
    if(a < b){ a = b; return true; } return false;
}
/*
 * Modint struct
 * library author : @snuke
 * */
const int mod = 998244353;
struct mint {
  long long x; // typedef long long ll;
  mint(long long x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) { if((x+=a.x)>=mod)x-=mod;return *this;}
  mint& operator-=(const mint a) { if((x+=mod-a.x)>=mod)x-=mod; return *this;}
  mint& operator*=(const mint a) { (x *=a.x)%=mod; return *this;}
  mint operator+(const mint a) const { mint res(*this);return res+=a;}
  mint operator-(const mint a) const { mint res(*this);return res-=a;}
  mint operator*(const mint a) const { mint res(*this);return res*=a;}
  mint pow(ll t) const {
    if (!t) return 1;mint a = pow(t>>1);a*=a;
    if (t&1) a *= *this;return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return (*this) *= a.inv();}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int64_t n,s;cin >> n >> s;
    vector<int64_t> a(n);rep(i,n)cin >> a[i];

    vector<mint> dp(3010,0);
    mint ans = 0;
    rep(i,n){
        dp[0] += 1;
        vector<mint> tmp = dp;
        for(int j = s + 1 - a[i];j >= 0;j--) dp[j + a[i]] += tmp[j];
        ans += dp[s];
    }
    cout << ans << '\n';
}