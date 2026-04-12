#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> S >> K;
  char x = S[K-1];
  for(int i=0;i<N;i++){
    if(S[i]==x){
      cout << S[i];
    }else{
      cout << "*";
    }
  }
  cout <<endl;
}