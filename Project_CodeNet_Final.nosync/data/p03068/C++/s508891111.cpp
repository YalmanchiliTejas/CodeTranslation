#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N ;
  string S;
  cin >>S;
  cin >> K;
  for (int i=0; i<N; i++){
    if(S[i] != S[K-1]){
      S[i] = '*';
    }
    if(S[i] == S[K-1]){
      S[i] =S[i];
 
    }
  }
  cout << S <<endl;
}
  
