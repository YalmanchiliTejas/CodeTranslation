#include<iostream>
using namespace std;

int main(){
  char S[3];
  cin >> S;
  
  if(S[0] == S[1] && S[1] == S[2]){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  
  return 0;
}