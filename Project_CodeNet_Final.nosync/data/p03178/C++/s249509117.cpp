/*
 * atcoder/dp_3rd/s.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>

using namespace std;

#define ll long long

#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/* Mod */
#define MOD 1000000007
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%MOD+MOD)%MOD){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%MOD+MOD)%MOD; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
  mint& operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
ostream & operator << (ostream & out, mint const & v) {
  out << v.x;
  return out;
}

const int MAX = 10100;
string K;
int D, N;

// dp[l][n][d] := n桁目までみて制限状態lでこれまでの和がdである通りの数
// dp[l and k == K[n]][n+1][d+k] = dp[l][n][d] for k in [0:K[n]]
mint dp[2][MAX][110] = {0};

void input() {
  cin >> K >> D;
  N = K.size();
}

mint rec(int n = 0, int d = 0, bool l = true) {
  mint &cc = dp[l][n][d];
  if (cc.x >= 0) return cc;
  if (n==N) return cc = d == 0;
  int k_u = l ? K[n] - '0' : 9;
  mint ways = 0;
  for (int k=0; k<=k_u; k++) {
    ways += rec(n+1, (d+k)%D, l and k == k_u);
  }
  return cc = ways;
}

void memoRec() {
  memset(dp, -1, sizeof(dp));
  cout << rec() - 1 << endl;
}

mint give() {
  for (int k=0; k<=(K[0]-'0'); k++) dp[1][0][k] = 1;
  for (int n=0; n<N; n++) {
    for (int d=0; d<D; d++) {
      for (int l=0; l<=1; l++) {
        int k_upper = l ? K[n] - '0' : 9;
        for (int k=0; k<=k_upper; k++) {
          dp[l and k==k_upper][n+1][(d+k)%D] += dp[l][n][d];
        }
      }
    }
  }
  return dp[0][N][0] + dp[1][N][0] - 1;
}

void solve() {
  cout << give() << endl;
}

int main() {
  // cout.precision(15);
  input();
  // solve();
  memoRec();
  return 0;
}
