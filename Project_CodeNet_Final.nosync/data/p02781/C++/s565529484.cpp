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

ll Pow(ll A, ll B, ll mod){
  if (B == 0) return 1;
  else{
    if (B % 2 == 0){
      return Pow(A * A % mod, B / 2, mod) % mod;
    }else{
      return A * Pow(A * A % mod, B / 2, mod) % mod;
    }
  }
}

ll nCr(ll N, ll C, ll mod){
  ll ans = 1; C = min(C, N - C);
  for (ll i = 1; i <= C; i++){
    ans *= N - i + 1; ans %= mod;
    ans *= Pow(i, mod - 2, mod); ans %= mod;
  }
  return ans;
}

int main(){
  string S; cin >> S;
  int K; cin >> K;

  int N = S.length();
  ll DP1[N][K + 1], DP2[N][K + 1];

  for (int i = 0; i < K + 1; i++){
    DP1[0][i] = 0; DP2[0][i] = 0;
  }
  DP1[0][0] = 1; DP1[0][1] = S[0] - '0' - 1;
  DP2[0][1] = 1;

  for (int i = 1; i < N; i++){
    for (int j = 0; j < K + 1; j++){
      DP1[i][j] = DP1[i - 1][j];
    }
    for (int j = 1; j < K + 1; j++){
      DP1[i][j] += DP1[i - 1][j - 1] * 9;
    }

    if (S[i] == '0'){
      for (int j = 0; j < K + 1; j++){
        DP2[i][j] = DP2[i - 1][j];
      }
    }else{
      for (int j = 0; j < K + 1; j++){
        DP1[i][j] += DP2[i - 1][j];
      }

      int num = S[i] - '0' - 1;
      for (int j = 1; j < K + 1; j++){
        DP1[i][j] += DP2[i - 1][j - 1] * num;
      }
      
      DP2[i][0] = 0;
      for (int j = 1; j < K + 1; j++){
        DP2[i][j] = DP2[i - 1][j - 1];
      }
    }
  }
  
  cout << DP1[N - 1][K] + DP2[N - 1][K] << endl;

  
  return 0;
}
