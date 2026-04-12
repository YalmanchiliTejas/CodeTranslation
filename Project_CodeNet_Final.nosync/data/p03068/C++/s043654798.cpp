#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  string S;
  cin>>N>>S>>K;
  char X=S.at(K-1);
  for(int Y=0;Y<N;Y++){
    if(S.at(Y)==X){
      cout<<X;
    }
    else{
      cout<<'*';
    }
  }
}