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

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main() {
  Cin(int, n);
  Cins(int, n, h);

  int ans = 1;
  for (int i = 1; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < i; ++j)
      if (h[i] < h[j]) ok = false;
    if (ok) ans++;
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  Main();
  return 0;
}