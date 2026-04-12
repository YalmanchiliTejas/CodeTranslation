#include<iostream>
using namespace std;

int main(){
  char S[3];
  cin >> S;
  
  for(int i=0; i<2; i++){
    if(S[i] != S[i+1]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  
  return 0;
}