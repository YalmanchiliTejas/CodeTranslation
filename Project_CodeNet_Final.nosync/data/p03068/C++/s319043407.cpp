#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
  int N;
  cin>>N;
  string S;
  char SS[N];
  cin>>S;
  int K;
  cin>>K;
  for(int i=0; i<N; ++i){
    if(S.at(i)!=S.at(K-1)) SS[i]='*';
    else SS[i]=S.at(i);
  }
  for(int i=0; i<N-1; ++i) cout<<SS[i];
  cout<<SS[N-1]<<endl;
  
}
