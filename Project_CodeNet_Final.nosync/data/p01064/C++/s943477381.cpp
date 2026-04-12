#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int main() {

  int N, a, d, M; cin >> N >> a >> d >> M;
  int x[M], y[M], z[M];
  rep(i, M) {
    cin >> x[i] >> y[i] >> z[i];
    y[i]--, z[i]--;
  }

  int K; cin >> K; K --;

  for(int i=M-1; i>=0; i--) {
    if(x[i] == 0) {
      if(y[i] <= K && K <= z[i]) {
        K = z[i] - (K - y[i]);
      }
    }
  }

  int tar = a + K * d;

  for(int i=0; i<M; i++) {
    if(x[i] == 0) {
      if(y[i] <= K && K <= z[i]) {
        K = z[i] - (K - y[i]);
      }
    }
    if(x[i] == 1) {
      if(y[i] <= K && K <= z[i]) {
        tar ++;
      }
    }
    if(x[i] == 2) {
      if(y[i] <= K && K <= z[i]) {
        tar /= 2;
      }
    }
  }

  cout << tar << endl;

  return 0;
}