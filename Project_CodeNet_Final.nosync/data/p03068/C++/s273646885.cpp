#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  string S;
  cin >> S;
  int K;
  scanf("%d", &K);

  for (int i = 0; i < N; ++i){
    if(S[i]!=S[K-1]) S[i] = '*';
  }

  cout << S << endl;


}