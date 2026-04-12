#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  char nochange = S[K-1];
  for(int i = 0; i < N; i++){
    if (S[i] != nochange){
      S.replace(i, 1, "*");
    }
  }
  cout << S << endl;
}