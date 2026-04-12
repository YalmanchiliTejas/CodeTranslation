#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  if(s == "AAA") cout << "No";
  else if(s[0]=='A' || s[1]=='A' || s[2]=='A') cout << "Yes";
  else cout << "No";
  cout << endl;
  
  return 0;
}
