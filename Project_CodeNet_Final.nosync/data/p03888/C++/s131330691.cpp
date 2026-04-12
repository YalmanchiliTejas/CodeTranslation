#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;

void solve(ll test_num) {
  (void) test_num;
  ll r1, r2;
  cin >> r1 >> r2;
  const dd res = 1.0 / (1.0 / r1 + 1.0 / r2);
  cout << fixed << setprecision(7) << res << endl;
}

void init() {

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("/home/azneye/Documents/Stuff/input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  ll tests = 1;
  //cin >> tests;
  for (ll test = 1; test <= tests; ++test) {
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}