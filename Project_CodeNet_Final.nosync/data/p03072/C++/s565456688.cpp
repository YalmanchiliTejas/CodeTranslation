#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N ; 
  cin >> N ; 
  int cnt = 0 ; 
  vector<int> H(N) ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> H.at(i) ; 
  }
  int max = H.at(0) ; 
  
  for(int i = 1 ; i < N ; i++){
    if( max <= H.at(i) ){
      max = H.at(i) ; 
      cnt++ ; 
    }
  }  
  
  cout << cnt+1 << endl ; 
  
}