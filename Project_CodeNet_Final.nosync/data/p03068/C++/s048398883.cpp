#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N; cin >> N;
  string S; cin >> S;
  int K; cin >> K;

  char e = S[K-1];
  for (char s : S) {
    if (s == e) cout << s;
    else cout << '*';
  }
  cout << endl;

  return 0;
}
