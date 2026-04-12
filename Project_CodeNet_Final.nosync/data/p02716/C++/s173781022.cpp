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
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

int N;
const int Size = 2e5;
ll A[Size + 5], DP[Size + 5][2][2];

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  DP[1][1][1] = A[1];
  for (int i = 2; i <= N; i++){
    if (i % 2 == 0){
      DP[i][0][0] = max(DP[i-1][0][0], DP[i-1][0][1]);
      DP[i][1][0] = DP[i-1][1][1];
      DP[i][1][1] = DP[i-1][0][0] + A[i];
    }else{
      DP[i][0][0] = max(DP[i-1][1][0], DP[i-1][1][1]);
      DP[i][0][1] = DP[i-1][0][0] + A[i];
      DP[i][1][1] = DP[i-1][1][0] + A[i];
    }
  }

  if (N % 2 == 0){
    cout << max(DP[N][1][0], DP[N][1][1]) << endl;
  }else{
    cout << max(DP[N][0][0], DP[N][0][1]) << endl;
  }

  return 0;
}
