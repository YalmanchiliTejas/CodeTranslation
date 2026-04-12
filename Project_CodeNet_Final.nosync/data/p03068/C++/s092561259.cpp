#include <bits/stdc++.h>
using namespace std;

void ioinit() { ios::sync_with_stdio(0); cin.tie(0); }

int main() {
  ioinit();
  int N, K;
  string S;
  cin >> N >> S >> K;
  for(int i = 0; i < N; i++){
    if(S[i] != S[K-1]) S[i] = '*';
  }

  cout << S << endl;
}
