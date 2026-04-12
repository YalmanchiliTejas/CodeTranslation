#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  
  cin >> N >> S >> K;
  
  char tgt = S.at(K - 1);
  
  for (int i = 0; i < S.size(); i++) {
    char c = S.at(i);
    if (c != tgt) {
      S.at(i) = '*';
    }
  }
  
  cout << S << endl;
}
