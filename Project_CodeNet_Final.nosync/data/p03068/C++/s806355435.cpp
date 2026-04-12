#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int N, K;
  char S[12];

  cin >> N >> S >> K;

  char t = S[K - 1];
  for (int i = 0; i < N; i++) {
    S[i] = S[i] != t ? '*' : t;
  }

  cout << S << endl;

  return 0;
}