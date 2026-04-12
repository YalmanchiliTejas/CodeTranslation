#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;
struct modint {
  long long val;
  modint(long long val=0) : val((val % MOD + MOD) % MOD){}
  modint operator-() const { return modint(-val); }
  modint& operator+=(const modint a) { if ((val += a.val)     >= MOD) val -= MOD; return *this; }
  modint& operator-=(const modint a) { if ((val += MOD-a.val) >= MOD) val -= MOD; return *this; }
  modint& operator*=(const modint a) { (val *= a.val) %= MOD; return *this; }
  modint operator+(const modint a) const { return (modint)*this += a; }
  modint operator-(const modint a) const { return (modint)*this -= a; }
  modint operator*(const modint a) const { return (modint)*this *= a; }
  modint pow(long long n) const { modint r(1), m(val); while (n > 0) { if (n & 1) {r *= m;} m *= m; n >>= 1; } return r; }
  modint inv() const { return pow(MOD-2); }
  modint& operator/=(const modint a) { return (*this) *= a.inv(); }
  modint operator/(const modint a) const { return (modint)*this /= a; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  friend ostream &operator<<(ostream &os, const modint &p) { return os << p.val; }
  friend istream &operator>>(istream &is, modint &a) { long long t; is >> t; a = modint(t); return (is); }
};

string K;
int D;
modint dp[10001][100][2];

signed main() {
  cin >> K >> D;
  int n = K.size();

  dp[0][0][0] = 1;

  for(int i=1; i<=n; i++) {
    int s = (int)(K[i-1] - '0');
    for(int sum=0; sum<D; sum++) {
      for(int d=0; d<=9; d++) dp[i][(sum+d)%D][1] += dp[i-1][sum][1];
      for(int d=0; d<s; d++)  dp[i][(sum+d)%D][1] += dp[i-1][sum][0];
      dp[i][(sum+s)%D][0] += dp[i-1][sum][0];
    }
  }
  cout << dp[n][0][1] + dp[n][0][0] - 1<< endl;
}
