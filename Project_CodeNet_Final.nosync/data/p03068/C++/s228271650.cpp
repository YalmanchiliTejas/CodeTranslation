#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, K;
  string S;
  cin >> N >> S >> K;
  char a = S.at(K - 1);
  for(char b : S){
    if(a == b)cout << a;
    else cout << '*';
  }
  cout << endl;
  return 0;
}