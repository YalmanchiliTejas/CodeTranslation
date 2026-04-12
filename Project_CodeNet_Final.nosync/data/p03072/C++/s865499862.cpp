#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; ++i) cin >> h[i];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < i; ++j) {
      if (h[j] > h[i]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}