#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  int count_A=0;
  int count_B=0;
  
  for(int i=0;i<3;i++){
    if(S.at(i)=='A'){
      count_A++;
    }
  }

  for(int i=0;i<3;i++){
    if(S.at(i)=='B'){
      count_B++;
    }
  }
  
  if(count_A==0 || count_B==0){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}
  
  