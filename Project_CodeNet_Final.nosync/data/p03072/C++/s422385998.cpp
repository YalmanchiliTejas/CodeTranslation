#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;

int main() {
  int N;
  cin >> N;
  int h, mx = 0, ret = 0;
  for (int i = 0; i < N; i++) {
    cin >> h;
    if (mx <= h) ret++;
    mx = max(h, mx);
  }
  cout << ret << endl;
}
