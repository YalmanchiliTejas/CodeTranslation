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

int N, M, ans;
vector <int> Graph[8];
bool visited[8];

int DFS(int Node, int turn){
  if (turn == N - 1){
    ans++; return 0;
  }

  visited[Node] = true;
  for (int i = 0; i < Graph[Node].size(); i++){
    int next = Graph[Node][i];
    if (!visited[next]){
      DFS(next, turn + 1);
    }
  }
  visited[Node] = false;
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }
  visited[0] = true;
  DFS(0, 0);
  cout << ans << endl;
  
  return 0;
}
