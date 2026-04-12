#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin>>N>>S>>K;
  for(char &c:S)
    if(c!=S[K-1])
      c='*';
  cout<<S<<endl;
}