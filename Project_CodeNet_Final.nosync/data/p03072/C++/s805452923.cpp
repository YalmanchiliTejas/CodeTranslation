#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int H[25];
  cin >> N;
  for(int i=0; i <N ;i++) cin >> H[i] ;
  
  int HMAX=0;
  int count=0;
  for(int i=0; i <N ;i++){
    if(HMAX <= H[i]){
      HMAX=H[i];
      count++;
    }
  }
    
  cout<< count<< endl;
  }
  
