#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll N, K;
  string S;
  cin >> N >> S >> K;
  char s = S[K-1];
  for (int i = 0; i < S.size(); ++i) {
    if(S[i] != s)
      S[i] = '*';
  }
  cout << S << endl;
}
