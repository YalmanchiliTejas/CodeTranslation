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

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int H, W;
int di[2] = {0, 1}, dj[2] = {1, 0};
char A[10][10];

int main(){
  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; i++) scanf("%s", A + i);

  queue <Pii> que;
  que.push({0, 0});
  A[0][0] = '.';

  while(!que.empty()){
    Pii Q = que.front(); que.pop();
    
    int cnt = 0;
    for (int k = 0; k < 2; k++){
      int I = Q.fi + di[k], J = Q.se + dj[k];
      if (A[I][J] == '#'){
        cnt++; que.push({I, J});
        A[I][J] = '.';
      }
    }
    if (cnt == 2){
      printf("Impossible\n"); return 0;
    }
  }

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (A[i][j] == '#'){
        printf("Impossible\n");
        return 0;
      }
    }
  }
  printf("Possible\n");

  return 0;
}
