#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> S >> K;
  char a;
  for(int i=0;i<N;i++){
    if(i==K-1){
      a=S.at(i);
    }
  }
  
  for(int i=0;i<N;i++){
    if(S.at(i)==a){
      cout << S.at(i);
    }
    else{
      cout << "*";
    }
  }
  cout << endl;
}