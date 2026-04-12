#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define INF 1e9;
using namespace std;
typedef long long ll;
int main() {
  int N;
  cin >> N;
  int H[N];
  int max = 0;
  int cnt = 0;
  REP(i, N) {
    cin >> H[i];
    if (max <= H[i]) {
      cnt++;
      max = H[i];
    }
  }
  cout << cnt;
  return 0;
}