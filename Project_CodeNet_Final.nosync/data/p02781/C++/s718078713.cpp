#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
// clang-format on

string N;
vector<int> n;
int k;
int dp[100 + 5][2][100 + 5];

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  cin >> k;
  for (auto a : N) {
    n.push_back(a - '0');
  }
  int l = N.size();
  // 今の桁, samller, 0が含まれてる個数
  dp[0][0][0] = 1;
  for (int i = 0; i < l; i++) {
    for (int smaller = 0; smaller < 2; smaller++) {
      for (int j = 0; j < l; j++) {
        for (int x = 0; x <= (smaller ? 9 : n[i]); x++) {
          // 今の桁が0なら0の個数を一つインクリメントして、
          // それ以下のものを全部足し合わせる
          if (x == 0) {
            dp[i + 1][smaller || x < n[i]][j + 1] += dp[i][smaller][j];
          } else {
            dp[i + 1][smaller || x < n[i]][j] += dp[i][smaller][j];
          }
        }
      }
    }
  }

  cout << dp[l][0][l - k] + dp[l][1][l - k] << endl;

  return 0;
}
