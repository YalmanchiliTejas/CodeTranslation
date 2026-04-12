#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
using ll = long long;
using P = pair<int, int>;

const int mod = 998244353;
struct mint {
  ll x; 
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

  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

mint f(int n){ 
  if(n == 0)return 1;
  mint x = f(n / 2); 
  x *= x; 
  if(n % 2 == 1)x *= 2;
  return x;
}

mint choose(int n, int a){
  mint x = 1, y = 1;
  for(int i = 0; i < a; ++i){
    x *= n - i;
    y *= i + 1;
  }
  return x / y;
}

mint dp[3010][3010][3];

int main(){
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  fill((mint*)dp, (mint*)dp + sizeof(dp) / sizeof(mint), 0);
  dp[0][0][0] = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= s; ++j){
      dp[i + 1][j][0] += dp[i][j][0];
      dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
      dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
      if(j + a[i] <= s){
        dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1];
        dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1];
      }
    }
  }

  cout << dp[n][s][2].x << endl;
  
  return 0;
}
