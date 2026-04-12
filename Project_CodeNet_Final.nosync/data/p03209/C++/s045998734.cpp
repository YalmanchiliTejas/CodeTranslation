#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> Pati(N + 1), Maisuu(N + 1);
  Pati[0] = 1, Maisuu[0] = 1;
  for (int i = 1; i <= N; i++) {
    Pati[i] = 2 * Pati[i - 1] + 1;
    Maisuu[i] = 2 * Maisuu[i - 1] + 3;
  }
  ll ans = 0;
  for (int i = N; i >= 0; i--) {
    X--;
    if (X >= 0 && i == 0) {
      ans++;
      break;
    }
    if (i == 0) break;
    if (X >= Maisuu[i - 1]) {
      ans += Pati[i - 1];
      X -= Maisuu[i - 1];
    } else {
      continue;
    }
    X--;
    if (X >= 0) ans++;
    if (X >= Maisuu[i - 1]) {
      ans += Pati[i - 1];
      X -= Maisuu[i - 1];
      X--;
    } else {
      continue;
    }
  }
  cout << ans << endl;
}