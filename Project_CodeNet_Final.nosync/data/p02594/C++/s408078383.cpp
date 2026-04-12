#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &in, std::ostream &out);

int main() {
#ifdef LOCAL
  freopen("../IO/a.in", "r", stdin);
//  freopen("../IO/a.out", "w", stdout);
#else
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  solve(std::cin, std::cout);
  return 0;
}


void solve(std::istream &in, std::ostream &out) {
  int X;
  in >> X;
  out << (X >= 30 ? "Yes" : "No");
}