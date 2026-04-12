#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N,K;
  string S,ori;

  cin >>N>>S>>K;

  ori = S;

  for(int i = 0; i < N; i++){
      if(S[i] != ori[K-1]){
          S[i] = '*';
      }
  }

  cout <<S<<endl;
  return 0;
  }