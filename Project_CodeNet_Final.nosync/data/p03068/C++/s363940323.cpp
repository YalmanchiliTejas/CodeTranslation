#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K,N;
  string S;
  cin >> N >> S >> K;
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) != S.at(K-1)){
      S.at(i) = '*';
    }
  }
  cout << S << endl;
}
 