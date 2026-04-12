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

int N, M, Order[8];
vector <int> Graph[8];

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) Order[i] = i;

  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }
  
  int ans = 0;
  do{
    bool flag = true;

    for (int i = 0; i < N - 1; i++){
      flag = false;
      for (int j = 0; j < Graph[Order[i]].size(); j++){
        if (Graph[Order[i]][j] == Order[i + 1]) flag = true;
      }
      if (!flag) break;
    }

    if (flag) ans++;
  }while (next_permutation(Order + 1, Order + N));
  cout << ans << endl;

  return 0;
}
