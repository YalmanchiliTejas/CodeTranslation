#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
string S;
int main(){
cin >> S;
  if(S[0]==S[1] && S[1]==S[2]){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}