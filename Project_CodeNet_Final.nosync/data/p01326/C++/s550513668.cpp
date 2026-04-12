#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef long long int Int;
const int L = 8;
const Int MOD = 1000000;

void countXY(Int ys, Int yt, Int xs, Int xt, Int &x, Int &y, string &s){
  if(ys != -1) FOR(i, ys, yt) if(s[i] == 'x') ++y;
  if(xs != -1) FOR(i, xs, xt) if(s[i] == 'x') ++x;
}

Int countPattern(Int x, Int y, string s){
  bool t = 1;
  REP(i, s.length()) if(s[i] == '1') t = 0;
  Int a = 1, b = 1;
  REP(i, x) a = (a * 2 % MOD);
  REP(j, y) b = (b * 2 % MOD);
  if(t) b = (b - 1 + MOD) % MOD;
  return (a % MOD) * (b % MOD) % MOD;
}

bool check(string s){
  bool f = 0;
  REP(i, s.length()){
    if(s[i] == 'x') return 1;
    if(s[i] == '1') f = 1;
  }
  return f;
}

bool check_pref(string &s, string tar){
  REP(i, tar.length()) if(s[i] != 'x' && s[i] != tar[i]) return 0;
  return 1;
}

int main() {
  Int N;
  while(cin >>N && N){
    vector<string> v(N);
    REP(i, N) cin >>v[i];
    vector<Int> dp(N + 1, 0);
    dp[0] = 1;
    REP(i, N){
      if(check_pref(v[i], "0")){
        Int x = 0, y = 0;
        countXY(-1, -1, 1, L, x, y, v[i]);
        dp[i + 1] = ((dp[i] * countPattern(x, y, "1") % MOD) + dp[i + 1]) % MOD;
      }
      if(i + 1 < N && check_pref(v[i], "110") && check_pref(v[i + 1], "10") && check(v[i].substr(3, 4))){
        Int x = 0, y = 0;
        countXY(3, L - 1, L - 1, L, x, y, v[i]);
        countXY(-1, -1, 2, L, x, y, v[i + 1]);
        dp[i + 2] = ((dp[i] * countPattern(x, y, v[i].substr(3, 4)) % MOD) + dp[i + 2]) % MOD;
      }
      if(i + 2 < N && check_pref(v[i], "1110") && check_pref(v[i + 1], "10") && check_pref(v[i + 2], "10") && check(v[i].substr(4, 4) + v[i + 1].substr(2, 1))){
        Int x = 0, y = 0;
        countXY(4, L, -1, -1, x, y, v[i]);
        countXY(2, 3, 3, L, x, y, v[i + 1]);
        countXY(-1, -1, 2, L, x, y, v[i + 2]);
        dp[i + 3] = ((dp[i] * countPattern(x, y, v[i].substr(4, 4) + v[i + 1].substr(2, 1)) % MOD) + dp[i + 3]) % MOD;
      }
      if(i + 3 < N && check_pref(v[i], "11110") && check_pref(v[i + 1], "10") && check_pref(v[i + 2], "10") && check_pref(v[i + 3], "10") && check(v[i].substr(5, 3) + v[i + 1].substr(2, 2))){
        Int x = 0, y = 0;
        countXY(5, L, -1, -1, x, y, v[i]);
        countXY(2, 4, 4, L, x, y, v[i + 1]);
        countXY(-1, -1, 2, L, x, y, v[i + 2]);
        countXY(-1, -1, 2, L, x, y, v[i + 3]);
        dp[i + 4] = ((dp[i] * countPattern(x, y, v[i].substr(5, 3) + v[i + 1].substr(2, 2)) % MOD) + dp[i + 4]) % MOD;
      }
    }
    cout <<dp[N] <<endl;
  }
  return 0;
}