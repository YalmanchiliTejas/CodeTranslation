#include <iostream>
#include <vector>

using namespace std;
long long int MOD = 998244353LL;

int main() {
  
  int n, s; cin >> n >> s;
  
  vector<long long> F(s + 1, 0); // F[i] は x^i の係数

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    F[0]++;
    for (int i = s - a; i >= 0; i--) {
      (F[i + a] += F[i]) %= MOD;
    }

    (ans += F[s]) %= MOD;
  }

  cout << ans << endl;
  return 0;
}
