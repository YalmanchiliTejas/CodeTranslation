#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (N); ++i)
#define ALL(x) (x).begin(), (x).end()
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll div_ceil(ll, ll);

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  REP(i, N) { std::cin >> H.at(i); }
  int count = 1;
  REP(i, N) {
    bool ok = true;
    REP(j, i) {
      if (H.at(i) < H.at(j)) {
        ok = false;
      }
    }
    if (i != 0 && ok) {
      count++;
    }
  }
  std::cout << count << '\n';
}

ll div_ceil(ll a, ll b) {
  ll quotient = a / b;
  ll remainder = a % b;
  if (remainder == 0) {
    return quotient;
  } else {
    return quotient + 1;
  }
}
