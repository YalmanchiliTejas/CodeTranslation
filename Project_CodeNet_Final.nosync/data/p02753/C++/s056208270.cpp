#include <iostream>
using namespace std;
#include <string>

int main() {
  string s,ans;

  cin >> s;

  if(s=="AAA") {
    ans="No";
  }
  else if(s=="BBB") {
    ans="No";
  }
  else {
    ans="Yes";
  }

  cout << ans << endl;

  return 0;
}