#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  char s;
  s = S[K-1];

  for(int i=0; i<N; i++){
    if(S[i] != s) S[i] = '*';
  }
  cout << S << endl;
  return 0;
}