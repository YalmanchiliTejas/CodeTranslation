#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  int K;
  cin>>N>>S>>K;
  for(int i=0;i<N;i++){
    if(S.at(i)==S.at(K-1)){
      cout<<S.at(i);
    }else{
      cout<<"*";
    }
  }
  cout<<endl;
}