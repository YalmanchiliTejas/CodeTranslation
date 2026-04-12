#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define all(a) (a).begin(),(a).end()

int a[20][20];

void solve(int n) {
  memset(a, 0, sizeof a);
  int ci = n/2+1, cj = n/2;
  a[ci][cj] = 1;

  int val = 2;
  ci++;
  cj++;
  
  while (val <= n * n) {
    if (ci >= n) {
      ci %= n;
      continue;
    }
    if (cj >= n) {
      cj %= n;
      continue;
    }
    if (cj < 0) {
      cj = n - 1;
      continue;
    }
    if (a[ci][cj] == 0) {
      a[ci][cj] = val++;
      ci++;
      cj++;
      continue;
    }
    ci++;
    cj--;
    continue;
  }
  
  rep(i,n) {
    rep(j,n) printf("%4d", a[i][j]);
    puts("");
  }
}

int main() {
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}