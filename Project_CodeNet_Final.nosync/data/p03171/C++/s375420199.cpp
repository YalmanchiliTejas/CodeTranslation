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

int N; ll A[3005], DP[3005][3005];

ll Calc(int turn, int L, int R){
  if (DP[L][R] != 1e18) return DP[L][R];
  if (L == R){
    if (turn % 2 == 0) return DP[L][R] = A[L];
    else return DP[L][R] = -1 * A[L]; 
  }

  if (turn % 2 == 0){
    ll ans = max(A[L] + Calc(turn + 1, L + 1, R), A[R] + Calc(turn + 1, L, R - 1));
    return DP[L][R] = ans;
  }else{
    ll ans = min(-1 * A[L] + Calc(turn + 1, L + 1, R), -1 * A[R] + Calc(turn + 1, L, R - 1));
    return DP[L][R] = ans;
  }
}

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
  fill((ll*)DP, (ll*)(DP + N), 1e18);
  printf("%lld\n", Calc(0, 0, N - 1));
  return 0;
}
