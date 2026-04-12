#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
bool e[10][10];
bool visited[10];

int solve(int n) {
  bool all = true;
  for(int i=0;i<N;i++)if(!visited[i])all=false;
  if(all) return 1;

  int p = 0;
  for(int i = 0; i < N; i++) {
    if(e[n][i] == false) continue;
    if(visited[i]) continue;

    visited[i] = true;
    p += solve(i);
    visited[i] = false;
  } 
  return p;
}


int main() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    e[a-1][b-1] = e[b-1][a-1] = true;
  }

  visited[0] = true;
  std::cout << solve(0) << std::endl;
  return 0;
}
