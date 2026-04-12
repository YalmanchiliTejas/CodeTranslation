#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N;
  char S[N];
  cin>>S>>K;
  for (int i=0;i<N;i++){
    if(S[i]!=S[K-1]){
      S[i]='*';
    }
  }
  cout<<S<<endl;
}