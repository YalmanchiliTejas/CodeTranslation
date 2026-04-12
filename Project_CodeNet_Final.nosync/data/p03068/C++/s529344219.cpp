#include<iostream>
using namespace std;

int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  char mozi = S[K-1];
  char ast = '*';
  for(int i=0; i<N; i++){
    if(S[i] != mozi) S[i] = ast;
  }
  cout << S <<endl;
  return 0;
}