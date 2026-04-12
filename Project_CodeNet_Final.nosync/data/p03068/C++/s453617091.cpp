#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,K;
  string S;
  cin>>N;
  cin>>S;
  cin>>K;
  string A;
  for(int i=0; i<N; i++){
    if(S[i]==S[K-1]){
      A=A+S[i];
    }
    else{
      A=A+'*';
    }
  }
  cout <<A<<endl;
}