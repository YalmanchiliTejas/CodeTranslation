#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define all(arr) arr.begin(), arr.end()

using namespace std;
typedef long long ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

int main() {
  Cin(int, x, y, z);

  int used = z + y + z;
  for (int i = 1;; ++i) {
    if (used > x) {
      cout << i - 1 << endl;
      break;
    }
    used += z + y;
  }

  return 0;
}