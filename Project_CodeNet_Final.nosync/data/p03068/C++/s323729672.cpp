#include<bits/stdc++.h>
using namespace std;
signed main(){
  int N,K;
  string S;
  cin>>N>>S>>K;
  char C=S[K-1];
  for (int i=0; i<N; i++){
    if(S[i]!=C)S[i]='*';
  }
  cout<<S<<endl;
}
