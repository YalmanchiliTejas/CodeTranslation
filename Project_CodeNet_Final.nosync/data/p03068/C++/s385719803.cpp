#include <iostream>
using namespace std;
int main() {
  string S;
  int N, K;
  char r;
  cin >> N >> S >> K;
  r = S[K - 1];
  for(int i = 0; i < N; ++i) 
    if(i == K - 1) continue;
    else if(S[i] != r) S[i] = '*';
  cout << S << endl;
  return 0;
}
