#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int k;
  cin >> s >> k;

  int l = s.size();
  vvt<vt<i64>> dp(l + 1, vvt<i64>(2, vt<i64>(k + 2, 0)));
  dp[0][0][0] = 1;

  rep(i, 0, l) {
    int d = s[i] - '0';
    rep(smaller, 0, 2) {
      rep(j, 0, k + 1) {
        rep(m, 0, (smaller ? 9 : d) + 1) {
          dp[i + 1][smaller || m < d][j + (m != 0)] += dp[i][smaller][j];
        }
      }
    }
  }
  cout << dp[l][0][k] + dp[l][1][k] << endl;
}