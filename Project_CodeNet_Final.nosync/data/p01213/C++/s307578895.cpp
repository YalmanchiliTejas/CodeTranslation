#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_LEN = 300;

const int dxs[] = {0, -1, -1,  0};
const int dys[] = {0, -1,  0, -1};

/* typedef */

/* global variables */

int dp[MAX_LEN + 1][MAX_LEN + 1], prvs[MAX_LEN + 1][MAX_LEN + 1];

/* subroutines */

string max_substr(string str, int i0) {
  int len = str.length();

  memset(dp, 0, sizeof(dp));
  memset(prvs, 0, sizeof(prvs));

  for (int i = 0; i < i0; i++)
    for (int j = 0; j < len - i0; j++) {
      if (str[i] == str[i0 + j]) {
	dp[i + 1][j + 1] = dp[i][j] + 1;
	prvs[i + 1][j + 1] = 1;
      }
      else if (dp[i][j + 1] >= dp[i + 1][j]) {
	dp[i + 1][j + 1] = dp[i][j + 1];
	prvs[i + 1][j + 1] = 2;
      }
      else {
	dp[i + 1][j + 1] = dp[i + 1][j];
	prvs[i + 1][j + 1] = 3;
      }
    }

  int si = i0, sj = len - i0;
  stringstream ss;
  
  for (;;) {
    int di = prvs[si][sj];
    if (di == 0) break;
    si += dxs[di];
    sj += dys[di];
    if (di == 1) ss << str[si];
  }

  string res = ss.str();
  reverse(res.begin(), res.end());
  return res;
}

/* main */

int main() {
  for (;;) {
    string str;
    cin >> str;
    if (str == "#END") break;

    int len = str.length();
    string maxstr;

    for (int k = 1; k < len; k++) {
      string s = max_substr(str, k);
      if (maxstr.length() < s.length()) maxstr = s;
    }

    cout << maxstr << endl;
  }

  return 0;
}