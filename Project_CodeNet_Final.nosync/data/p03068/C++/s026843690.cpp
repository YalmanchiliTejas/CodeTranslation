#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N;
  string S;
  cin>>S;
  cin>>K;
  char sk=S[K-1];
  //cout<<sk<<endl;
  for(int i=0;i<N;i++){
    if (S[i]==sk){
      cout<<sk;
    }else{
      cout<<"*";
    }
	
    
  }
  cout<<endl;
  return 0;
}