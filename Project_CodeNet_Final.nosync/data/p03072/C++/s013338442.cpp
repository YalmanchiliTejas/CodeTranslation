#include"bits/stdc++.h"
#include"math.h"
using namespace std;

int main(){
 int N;
  cin >>N;
  vector<int> H(N);
  for(int i =0 ; i<N; i++){
    cin >> H.at(i);}
  
  int sum=1;
  bool T=true;
  for(int i=1; i<N; i++){
    
    for(int j=0; j<i; j++){
      
      if(H.at(i)<H.at(j)){
        T=false; break;}}
      
      if(T){sum++;}
  else{T=true;}}
  cout << sum <<endl;}