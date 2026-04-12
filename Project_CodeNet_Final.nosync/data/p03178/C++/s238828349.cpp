//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

ll DP1[10005][100], DP2[10005][100];

int main(){
  string S; cin >> S;
  int D; cin >> D;

  DP1[0][0] = 0;
  DP2[0][0] = 1;

  for (int i = 1; i <= S.length(); i++){
    int now = S[i - 1] - '0';

    for (int j = 0; j < D; j++){
      for (int k = 0; k < 10; k++){
        DP1[i][(j + k) % D] += DP1[i - 1][j];
      }
    }

    for (int j = 0; j < D; j++){
      for (int k = 0; k < now; k++){
        DP1[i][(j + k) % D] += DP2[i - 1][j];
      }
    }
    
    for (int j = 0; j < D; j++){
      DP2[i][(j + now) % D] += DP2[i - 1][j];
    }

    for (int j = 0; j < D; j++){
      DP1[i][j] %= nmax;
      DP2[i][j] %= nmax;
    }
  }

  ll ans = DP1[S.length()][0] + DP2[S.length()][0] + nmax - 1;
  cout << ans % nmax << endl;

  return 0;
}
