#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int ans = 0;
  ans += 800 * N;
  ans -= (int)(N / 15) * 200;
  cout << ans << endl;
  return 0;
}