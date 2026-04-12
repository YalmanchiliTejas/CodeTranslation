#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  string ans;
  if (S == "AAA" || S == "BBB") ans = "No";
  else ans = "Yes";
  
  cout << ans << endl;
  return 0;
}