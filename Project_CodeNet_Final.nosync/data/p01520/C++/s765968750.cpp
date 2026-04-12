/*
 * 2406.cc: Al dente
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100;

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int n, t, e;
  cin >> n >> t >> e;

  int ans = -1;
  
  for (int i = 0; ans < 0 && i < n; i++) {
    int xi;
    cin >> xi;
    int rem = t % xi;
    if (rem <= e || rem >= xi - e) {
      ans = i + 1;
      break;
    }
  }

  printf("%d\n", ans);
  return 0;
}