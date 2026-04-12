#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int mod = 998244353;
class mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
    mint choose(int n, int a){
        mint x = 1 ,y = 1;
        for(int i = 0; i < a; ++i){
            x *= n-i;
            y *= i+1;
        }
        return x / y;
    }
    friend istream& operator>>(istream& is, mint& m){
        is >> m.x;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

mint dp[3010][3010][4];

int main(){
  int n,s;
  cin>>n>>s;
  vector<int>a(n);
  rep(i,n)cin>>a[i];

  dp[0][0][0]=1;
  for(int i=0; i<n; ++i){
    for(int j=0; j<=s; ++j){
      for(int k=0; k<=2; ++k){
        if(a[i]+j<=s){
          if(k==0)dp[i+1][j+a[i]][k+2]+=dp[i][j][k];
          if(k==1)dp[i+1][j+a[i]][k]+=dp[i][j][k];
          dp[i+1][j+a[i]][k+1]+=dp[i][j][k];
        }
        dp[i+1][j][k]+=dp[i][j][k];
        dp[i+1][j][k+1]+=dp[i][j][k];
      }
    }
  }
  cout<<dp[n][s][2]<<endl;
  /*rep(k,3){
      rep(j,s+1){
          rep(i,n+1){
              cout<<dp[i][j][k]<<" ";
          }
          cout<<endl;
      }
      cout<<endl;
  }*/
}