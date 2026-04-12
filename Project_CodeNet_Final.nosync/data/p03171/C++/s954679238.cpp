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

int N;
ll A[3000];
ll DP[3000][3000];

ll Calc(int L, int R){
  if (DP[L][R] != 1e16) return DP[L][R];
  
  if (L == R){
    if (N % 2 == 0) return DP[L][R] = -1 * A[L];
    else return DP[L][R] = A[L];
  }

  ll ans;
  if (N % 2 == 0){
    if ((R - L) % 2 == 0){
      ans = min(Calc(L + 1, R) - A[L], Calc(L, R - 1) - A[R]);
    }else{
      ans = max(Calc(L + 1, R) + A[L], Calc(L, R - 1) + A[R]);
    }
  }else{
    if ((R - L) % 2 == 0){
      ans = max(Calc(L + 1, R) + A[L], Calc(L, R - 1) + A[R]);
    }else{
      ans = min(Calc(L + 1, R) - A[L], Calc(L, R - 1) - A[R]);
    }
  }
  return DP[L][R] = ans;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  fill((ll*)DP, (ll*)(DP + N), 1e16);

  cout << Calc(0, N - 1) << endl;
  
  return 0;
}
