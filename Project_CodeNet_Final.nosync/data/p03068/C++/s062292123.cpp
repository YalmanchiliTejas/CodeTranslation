#include <iostream>

using namespace std;

int main(void){
  int N, K;
  string S;

  cin >> N >> S >> K;

  char target = S[K-1];

  for (int i = 0; i < N; i++) {
    if (S[i] != target) {
      S[i] = '*';
    }
  }

  cout << S << '\n';

  return 0;
}