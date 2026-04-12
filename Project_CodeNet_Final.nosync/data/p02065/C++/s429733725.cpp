#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 210

ll dp[SIZE][SIZE][1<<10]; //現, 上, 履歴

int main(){
  int N, K, M;
  bool t[2][SIZE];

  cin >> N >> K >> M;

  dp[0][0][0] = 1;

  int mask = (1 << K) - 1;

  for (int i=0; i<=N*2; i++) {
    for (int u=0; u<=i && u<=N; u++) {
      for (int r=0; r<(1<<K); r++) {
        if (!dp[i][u][r]) continue;

        int d = i - u;

        t[0][d] = false;
        t[1][u] = false;
        if (u > 0) t[0][u-1] = false;
        if (d > 0) t[1][d-1] = false;

        int tmpU = u, tmpD = d;

        for (int j=0; j<K && j<i; j++) {
          if (r & (1<<j)) {
            tmpU--;
            t[0][tmpU] = true;
          } else {
            tmpD--;
            t[1][tmpD] = true;
          }
        }

        //上
        if (u < N && (u == 0 || t[0][u-1])) {
          dp[i+1][u+1][((r << 1)&mask) + 1] += dp[i][u][r];
          dp[i+1][u+1][((r << 1)&mask) + 1] %= M;
        }

        //下
        if (d < N && d < u && t[0][d] && (d == 0 || t[1][d-1])) {
          dp[i+1][u][((r << 1)&mask) + 0] += dp[i][u][r];
          dp[i+1][u][((r << 1)&mask) + 0] %= M;
        }
      }
    }
  }

  ll ans = 0;

  for (int i=0; i<(1<<K); i++) {
    ans += dp[N*2][N][i];
  }

  cout << ans % M << endl;

  return 0;
}

