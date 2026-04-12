#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

int main() {
  int N;
  cin >> N;
  VI a(N);
  rep(i, N) { cin >> a.at(i); }
  if (N == 2) {
    cout << max(a.at(0), a.at(1)) << endl;
    return 0;
  }
  ll maxi = max(max(a.at(0), a.at(1)), a.at(2));
  ll left = a.at(0);
  ll emax = max(a.at(0), a.at(1));
  for (int i = 4; i < N + 1; i++) {
    if (i % 2 == 0) {
      left += a.at(i - 2);
      emax = max(emax + a.at(i - 1), left);
    } else {
      maxi = max(emax, maxi + a.at(i - 1));
    }
  }
  if (N % 2 == 0) {
    cout << emax << endl;
  } else {
    cout << maxi << endl;
  }
  return 0;
}
