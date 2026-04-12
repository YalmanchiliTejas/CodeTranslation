#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

ll mod_pow(int x, int n) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % MOD, n / 2);
  if (n & 1) res = res * (ll)x % MOD;
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string N;
  int K;
  cin >> N >> K;
  int t = N.size();
  ll dp0[101][4];
  ll dp1[101][4];
  rep(i, t) {
    dp0[i][0] = 1;
    dp1[i][0] = 0;
  }
  dp0[0][1] = N[0]-'1';
  dp1[0][1] = 1;
  dp0[0][2] = 0;
  dp1[0][2] = 0;
  dp0[0][3] = 0;
  dp1[0][3] = 0;
  // cout << dp0[0][1] <<  ' ' << dp1[0][1] << endl;
  for (int i = 1; i < t; i++) {
    for (int j = 1; j <= 3; j++) {
      if (N[i] == '0') {
        dp0[i][j] = 9*dp0[i-1][j-1]+dp0[i-1][j];
        dp1[i][j] = dp1[i-1][j];
      }
      else {
        dp0[i][j] = 9*dp0[i-1][j-1]+dp0[i-1][j]+(N[i]-'1')*dp1[i-1][j-1]+dp1[i-1][j];
        dp1[i][j] = dp1[i-1][j-1];
      }
    }
  }
  // rep(i, t) {
  //   repto(j, 3) {
  //     cout << dp0[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // rep(i, t) {
  //   repto(j, 3) {
  //     cout << dp1[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << dp0[t-1][K]+dp1[t-1][K] << endl;
}
