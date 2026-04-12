#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
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
#define SIZE 200010


int main() {
  char S[SIZE];
  int K;
  ll dp[101][5][2] = {};


  scanf("%s%d", S, &K);

  int N = strlen(S);

  dp[0][0][0] = 1;

  for (int i=0; i<N; i++) {
    for (int j=0; j<10; j++) {
      for (int k=0; k<=3; k++) {
        if (S[i]-'0' > j) {
          dp[i+1][k+(j!=0)][1] += dp[i][k][1] + dp[i][k][0];
        } else if (S[i]-'0' == j) {
          dp[i+1][k+(j!=0)][0] += dp[i][k][0];
          dp[i+1][k+(j!=0)][1] += dp[i][k][1];
        } else {
          dp[i+1][k+(j!=0)][1] += dp[i][k][1];
        }
      }
    }
  }

  cout << dp[N][K][0] + dp[N][K][1] << endl;

  return 0;
}
