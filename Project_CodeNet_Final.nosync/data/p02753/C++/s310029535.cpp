#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "No";
  for(int i = 0; i < 3; i++){
      if(S.at(i) != S.at(0)) ans = "Yes";
  }
  cout << ans << endl;
}
