#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
int main() {
  int N,K,i;
  cin>>N;
  string S,T;
  cin>>S;
  cin>>K;
  T=S.at(K-1);
 for(i=0;i<N;i++){
   
 if(S.at(i)!=T.at(0)){
 S.replace(i,1,"*");
 }
 }

  cout<<S<<endl;
  
}