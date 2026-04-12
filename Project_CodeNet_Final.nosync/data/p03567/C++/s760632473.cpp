#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define all(arr) arr.begin(), arr.end()

using namespace std;

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
  Cin(string, s);

  for (int i = 0; i < sz(s) - 1; ++i) {
    if (s.substr(i, 2) == "AC") {
      puts("Yes");
      return 0;
    }
  }
  puts("No");

  return 0;
}