#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int dp[105][4][2];

int main() {
  string s; int k; cin >> s >>k;
  int n = s.length();
  // dp[i][j][eq] := seen i digits; j zero's eq=1: eq so far
  dp[0][0][1] = 1;
  rep(i,n) {
    rep(j,k+1) {
      rep(l, 2) {
        int x = s[i] - '0';
        rep(d, 10) {
          int ni = i+1, nj=j, eq=l;
          if (d!=0) nj++;
          if (nj > k) continue;
          if (l==1) {
            if (x < d) continue;
            if (x > d) eq = 0;
          }
          dp[ni][nj][eq] += dp[i][j][l];
        }
      }
    }
  } 
  cout << dp[n][k][0] + dp[n][k][1] << endl;
  return 0;
}