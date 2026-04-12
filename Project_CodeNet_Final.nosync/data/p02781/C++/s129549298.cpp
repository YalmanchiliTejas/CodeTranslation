#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
typedef long long ll;
 
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

#define INF 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { debug(itr); }
 
template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

// dp[i][j][k] 上からi桁目、まで見て0でない桁がj個ある。k=0のときNより大きくなる可能性があり、k=1のときはNより小さいことが確定している。
ll dp[102][5][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; 
  cin >> s;
  int k;
  cin >> k;

  int n = s.size();
  dp[0][0][0] = 1; 
  repr(i, n+1, 1) rep(j, k+1) rep(l, 2) {
    for (int d = 0; d < 10; ++d) {
      if (l == 0 && d > s[i-1] - '0') {
        continue;
      } 

      dp[i][j + (d > 0)][l | (d < s[i-1] - '0')] += dp[i-1][j][l];
    }
  }

  cout << dp[n][k][0] + dp[n][k][1] << endl;
}