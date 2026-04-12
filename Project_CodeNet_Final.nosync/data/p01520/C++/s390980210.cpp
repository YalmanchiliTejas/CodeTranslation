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

int N, T, E, x[102];

int solve() {
  rep(i,N) {
    if ((x[i] >= T) && (T + E >= x[i])) return i + 1;
    int d = T % x[i];
    if ((E >= d) || (E >= x[i] - d)) return i + 1;
  }
  return -1;
}

int main() {
  while (scanf("%d%d%d", &N, &T, &E) != -1) {
    rep(i,N) scanf("%d", x+i);
    printf("%d\n", solve());
  }
  return 0;
}