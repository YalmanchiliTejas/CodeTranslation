#include <iostream>
using namespace std;

char S[3];

int main(){
  cin >> S;
  if(S[0] == S[1] && S[1] == S[2]){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
}