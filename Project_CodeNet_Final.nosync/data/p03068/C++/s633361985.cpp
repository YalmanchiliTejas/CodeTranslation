#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;
  
  for(int i = 0; i < N; i++) {
    if(S.at(i) != S.at(K - 1)) {
      S.at(i) = '*';
    }
  }
  
  cout << S << endl;
}