#include<iostream>
#include<string>
using namespace std;
int main() {
  int a = 0;
  string S;
  cin >> S;
  for(int i = 1; i < S.size(); i++){
    if(S[i-1] == 'A' && S[i] == 'C'){
      cout << "Yes";
      a++;
      break;
    } 
  }
  if(a == 0) cout << "No";
  return 0;
}