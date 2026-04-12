#include <bits/stdc++.h>

#define rep(i, n) for(int (i) = 0; i < (n); ++(i))

using ll = long long int;
const ll MOD = 1e9 + 7;

int main() {
  std::string S;
  std::cin >> S;

  if(S[0] == S[1] && S[1]== S[2]) {
    std::cout << "No" << '\n';
  } else {
    std::cout << "Yes" << '\n';
  }
}
