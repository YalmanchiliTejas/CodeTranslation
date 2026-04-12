#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N; cin >> N;
  vector<int> H(N); REP(i, N) cin >> H[i];

  int ans = 0;
  int h = H[0];
  for (int i = 0; i < N; ++i) {
    if (H[i] >= h) {
      ans++;
      h = H[i];
    }
  }

  cout << ans << endl;
}