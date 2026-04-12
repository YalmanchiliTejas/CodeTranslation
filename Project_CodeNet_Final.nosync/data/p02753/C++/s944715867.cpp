#include<iostream>
using namespace std;

int main(){
  char S[3];
  for(int i=0;i<3;i++){cin >> S[i];}
  if(S[0] == S[1] && S[1]== S[2]){
    cout << "No" << endl;
  }
  else{cout << "Yes" << endl;}
}
