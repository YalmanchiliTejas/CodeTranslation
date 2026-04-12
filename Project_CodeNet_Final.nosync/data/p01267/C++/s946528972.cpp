#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define P pair<int, int>
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
const int MAX_N = 101;


int N, A, B, C, X, Y[MAX_N];

int rand(int x){
  return (A * x + B) % C;
}

int calc(){
  int ans = 0, cnt = 0, x = X;
  REP(i, 10001){
    if(Y[cnt] == x){
      ++cnt;
      if(cnt >= N) return i;
    }
    x = rand(x);
  }
  return -1;
}

int main() {
  while(cin >>N >>A >>B >>C >>X && N){
    REP(i, N) cin >>Y[i];
    cout <<calc() <<endl;
  }
  return 0;
}