#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(char c) {
  auto pred = false;
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      pred = true;
  }
  cout << (pred ? "vowel" : "consonant") << endl;
}

int main() {
  char c;
  cin >> c;
  solve(c);
  return 0;
}
