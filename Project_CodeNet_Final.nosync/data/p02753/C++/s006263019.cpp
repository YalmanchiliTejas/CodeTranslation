#include <iostream>
#include <string>
using namespace std;
string S;
int main() {
  cin >> S;
  bool ok = true;
  if(S[0] == S[1] && S[1] == S[2]) ok = false;
  cout << (ok?"Yes":"No") << endl;
}