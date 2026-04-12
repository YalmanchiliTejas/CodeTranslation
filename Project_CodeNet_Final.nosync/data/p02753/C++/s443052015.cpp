#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;

  bool can = false;
  if(S[0] != S[1] || S[1] != S[2] || S[0] != S[2]){
    can = true;
  }

  if(can) cout << "Yes" << endl;
  else  cout << "No" << endl;

  return 0;
}