#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;

const ll MAX = 111000;
bool can[MAX];

void solve(ll test_num) {
  (void) test_num;
  int N, Q;
  cin >> N >> Q;
  memset(can, false, sizeof(can));
  int ball = 1;
  can[1] = true;
  can[2] = true;
  for (int q = 0, a, b; q < Q; ++q) {
    cin >> a >> b;
    if (ball == a) {
      ball = b;
    } else if (ball == b) {
      ball = a;
    }
    swap(can[a], can[b]);
    can[ball - 1] = true;
    can[ball] = true;
    can[ball + 1] = true;
  }
  cout << count(can + 1, can + N + 1, true) << endl;
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