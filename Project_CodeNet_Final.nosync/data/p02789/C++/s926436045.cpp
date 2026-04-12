#include "bits/stdc++.h"

#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FORV(a, A) for (auto &a : A)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void Main() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
  return;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
