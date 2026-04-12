#include<bits/stdc++.h>
using namespace std;

int main(){
int N,K;
  string S;
  cin>>N;
  for(int i=0; i<N; i++){
   cin>>S[i];}
  cin>>K;

  for(int i=0; i<N; i++){
    if(S[i]!=S[K-1]){S[i]='*';}
  }
  
  for(int i=0; i<N; i++){
    cout<<S[i];}
  }