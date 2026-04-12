#include <iostream>

using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  char c = S[K - 1];
  for (auto &s : S) {
    s = (s == c ? s : '*');
  }
  cout << S << endl;
  return 0;
}
