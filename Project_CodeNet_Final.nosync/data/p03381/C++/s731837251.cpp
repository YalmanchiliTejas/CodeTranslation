#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 200000;

int N;
int A[kMaxN], B[kMaxN];

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }
  REP(i, N) { B[i] = A[i]; }

  sort(A, A+N);
  int k1 = A[N/2 - 1];
  int k2 = A[N/2];
  REP(i, N) {
    if (B[i] <= k1) {
      cout << k2 << endl;
    } else {
      cout << k1 << endl;
    }
  }

  return 0;
}
