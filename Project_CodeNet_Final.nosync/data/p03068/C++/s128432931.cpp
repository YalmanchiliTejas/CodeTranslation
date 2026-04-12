#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  int N;
  string S;
  int K;
  cin >> N >> S >> K;


  char k = S[K-1];
  for (int i = 0; i < N; i++) {
    if (k != S[i]) {
      S[i] = '*';
    }
  }
  cout << S << endl;
  
  return 0;
}