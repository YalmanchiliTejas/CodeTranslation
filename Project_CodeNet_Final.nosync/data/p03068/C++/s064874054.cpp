#include <bits/stdc++.h>
using namespace std;

int main(){

  int N; cin >> N;
  string S; cin >> S;
  int K; cin >> K;

  // cout << S << endl;

  // cout << N << "\t" << K << endl;
  char tmp = S[K-1];
  // cout << tmp << endl;

  
  for(int i = 0 ; i < N ; ++i){
    if(tmp != S[i]) S[i] = '*';
  }

  cout << S << endl;

}