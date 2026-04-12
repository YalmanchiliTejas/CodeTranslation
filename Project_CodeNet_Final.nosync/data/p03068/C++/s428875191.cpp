#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N;
  string b;
  char a;
  char c = '*';
  cin >> b;
  cin >> K;
  a = b[K-1];
  for (int j = 0;j<N;j++){
    if (b.at(j) != a){
      b.at(j) = c;
      cout << b.at(j);
    }
    else {
      cout << b.at(j);
    }
  }
  cout << endl;
}