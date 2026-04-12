#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  for(auto p : S) {
    if(p == S[K-1]) cout << p;
    else cout << "*";
  }
  return 0;
}
