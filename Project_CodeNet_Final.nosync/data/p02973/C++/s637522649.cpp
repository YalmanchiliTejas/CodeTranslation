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

#define fi first
#define se second
#define mp make_pair
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, A, DP[int(1e5 + 5)];

int main(){
  scanf("%d", &N);
  fill(DP, DP + N + 1, -1);
  for (int i = 0; i < N; i++){
    scanf("%d", &A);
    if (DP[0] < A){
      DP[0] = A; continue;
    }
    int L = 0, R = N;
    while (R - L > 1){
      int Mid = (L + R) / 2;
      if (A <= DP[Mid]) L = Mid;
      else R = Mid;
    }
    DP[R] = A;
  }

  for (int i = 0; i <= N; i++){
    if (DP[i] == -1){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}
