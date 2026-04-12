#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, A, sum, ans = 0, M = 1e9+7;
  cin >> N >> sum;
  while (cin >> A) (ans += sum * A % M) %= M, (sum += A) %= M;
  cout << ans << "\n";
}