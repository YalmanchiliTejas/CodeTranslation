#include <iostream>
using namespace std;
int main() {
  int a = 0, b = 0;
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
	if(s[i]=='A') a++;
    if(s[i]=='B') b++;
  }
  if (a == 0 || b == 0) cout << "No";
  else cout << "Yes";
  return 0;
}