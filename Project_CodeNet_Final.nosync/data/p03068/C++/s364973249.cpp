#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  
  char X= S.at(K-1);
  string A;
  
  for(int i=0; i<N; i++){
    if (S.at(i)==X){
      if(i==0){
        A=X;
      }
      else{
        A+=X;
      }
    }
    else{
      if(i==0){
        A='*';
      }
      else{
        A+='*';
      }
    }
  }
  
  cout << A << endl;
}