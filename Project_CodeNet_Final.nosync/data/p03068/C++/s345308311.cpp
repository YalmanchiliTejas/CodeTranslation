#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N, K, i;
  string S, c, tmp;

  cin >> N;
  cin >> S;
  cin >> K;

  c = S.substr(K-1, 1);

  for(i = 0; i < N; i++) {
    tmp = {S[i]};
    if(tmp != c) {
      S[i] = '*';
    }
  }

  cout << S << endl;
}


