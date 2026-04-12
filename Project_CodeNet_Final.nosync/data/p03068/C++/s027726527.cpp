#include <iostream>
using namespace std;

int main() {
  int K, N;
  string S;
  cin >> N;
  cin >> S;
  cin >> K;
  char r = S[K-1];
  for (int i = 0; i < N; i++) {
    cout << (S[i] == r ? r : '*');
  }
  cout << endl;
  return 0;
}
