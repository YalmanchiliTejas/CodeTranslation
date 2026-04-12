#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  for (int i = 0; i < N; i++) {
    if (S.at(i) != S.at(K - 1)) cout << '*';
    else cout << S.at(i);
  }
  cout << endl;
}