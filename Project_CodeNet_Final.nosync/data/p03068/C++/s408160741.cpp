#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;  cin >> N;
  string S;  cin >> S;
  int K;  cin >> K;
  
  char moji = S[K-1];
  
  for (int i = 0; i < N; i++) {
    if (S[i] == moji) {
      cout << moji;
    } else {
      cout << '*';
    }
  }
  cout << endl;

}