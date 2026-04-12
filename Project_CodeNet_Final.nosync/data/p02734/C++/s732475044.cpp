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

int N, S, A[3005];
ll DP[3005][3005];

int main(){
  cin >> N >> S;
  for (int i = 1; i <= N; i++) cin >> A[i];

  DP[0][0] = 1;
  for (ll i = 1; i <= N; i++){
    for (int j = 0; j <= S; j++){
      DP[i][j] = DP[i-1][j];
    }
    
    if (A[i] > S) continue;
    if (A[i] == S){
      DP[i][S] += i * (N - i + 1);
      DP[i][S] %= Mod;
    }else{
      DP[i][A[i]] += i;
    }

    for (int j = 1; j + A[i] < S; j++){
      DP[i][j + A[i]] += DP[i-1][j];
    }
    if (A[i] < S) DP[i][S] += DP[i-1][S - A[i]] * (N - i + 1);

    for (int j = 0; j <= S; j++){
      DP[i][j] %= Mod;
    }
  }
  cout << DP[N][S] << endl;

  return 0;
}
