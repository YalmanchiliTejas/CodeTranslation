#include <bits/stdc++.h>

#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  int H[20];
  cin >> N;
  REP(i, N) { cin >> H[i]; }

  int result = 0;
  bool ok = true;
  REP(i, N) {
    ok = true;
    REP(j, i) {
      if (H[j] > H[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++result;
    }
  }

  cout << result << endl;

  return 0;
}
