#include "bits/stdc++.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <random>
#include <stdio.h>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef string ST;


#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) for(auto (a): v )   cerr << a << endl
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl



vector<vector<LL>> A;
LL N, M;
LL cnt=0;
void recusive( LL now_index, vector<LL> visit)
{
  //visit.insert(now_index);
  visit.push_back(now_index);
  if (visit.size() == N) {
    cnt++;
    //PRINTSP(visit);
    return;
  }

  auto a = A[now_index];
  for (LL i = 0; i < a.size(); i++) {
    //if (visit.fin(a[i]) == visit.end()) {
    if(find(ALL(visit),a[i]) == visit.end()){
     recusive(a[i], visit);
    }
  }

}

void func() {
  cin >> N >> M;
  A.resize(N);
  REP(i, M) {
    LL a, b;
    cin >> a >> b;
    a--;
    b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }

  //set<LL> visit;
  vector<LL> visit;
  recusive(0, visit);
  cout << cnt;
#if 0
  REP(i, N) {
    cerr << i << " : ";
    PRINTSP(A[i]);
  }
#endif

}

#ifdef CALC_TIME 
#include <windows.h>
int main()
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  LARGE_INTEGER start, end;
  QueryPerformanceCounter(&start);
  // 何かの処理
  func();
  QueryPerformanceCounter(&end);
  double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
  fprintf(stderr, "\n%lf[ms]\n", time);
  return 0;
}
#else 
int main()
{
  func();
  return 0;
}
#endif



