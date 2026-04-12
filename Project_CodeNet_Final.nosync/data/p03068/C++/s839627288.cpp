#include <bits/stdc++.h>
using namespace std;
int main(void){
  int N;
  string S;
  int K;
  
  cin >> N >> S >> K;
  char target = S.at(K-1);
  for (char &c: S) {
    if (c != target) { c = '*'; }
  }
  cout << S;
}