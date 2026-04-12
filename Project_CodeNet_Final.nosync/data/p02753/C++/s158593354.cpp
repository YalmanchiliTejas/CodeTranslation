#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string S; cin >> S;
  if(S.find("AAA") == 0 || S.find("BBB") == 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}