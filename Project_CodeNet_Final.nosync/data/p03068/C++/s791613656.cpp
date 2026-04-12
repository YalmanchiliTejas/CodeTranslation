#include <bits/stdc++.h>
using namespace std;
int main(void){
  int N, K;
  string S;
  cin >> N >> S >> K;
  char target;
  target = S.at(K-1);
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == target) {
      cout << target;
    } else {
      cout << '*';
    }
  }
  cout << endl;
}
