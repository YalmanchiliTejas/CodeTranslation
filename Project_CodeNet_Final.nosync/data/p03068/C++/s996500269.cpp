#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;

  string moji = S.substr(K-1, 1);

  for(int i = 0; i < N; i++){
    if(S.substr(i, 1) != moji){
      S.replace(i, 1, "*");
    }
  }

  cout << S << endl;
}