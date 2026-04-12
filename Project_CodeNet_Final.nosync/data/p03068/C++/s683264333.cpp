#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
string S;
void solve() {
  char tmp = S[K - 1];
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == tmp) {
      cout << tmp;
    }
    else {
      cout << "*";
    }
  }
  cout << "\n";
  return;
}

int main() {
  cin >> N >> S >> K;
  solve();
  return 0;
}
