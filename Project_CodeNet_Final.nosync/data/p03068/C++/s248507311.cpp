#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;

  char target = S.at(K - 1);
  for (int i = 0; i < N; i++) {
    if (S.at(i) == target)
      cout << S.at(i);
    else
      cout << '*';
  }

  cout << endl;
}