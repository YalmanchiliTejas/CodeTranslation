#include<bits/stdc++.h>

using namespace std;

signed main() {
  int N,K;
  string S;
  cin >> N >> S >> K;
  char sk = S[K-1];
  for(auto c : S) {
    if(sk == c) cout << c;
    else cout << "*";
  }
  cout << endl;
  return 0;
}