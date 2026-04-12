#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  string a;
  cin >> a;
  string ans = "consonant";
  if(a=="a"||a=="i"||a=="u"||a=="e"||a=="o") ans="vowel";
  cout << ans << endl;
  return 0;
}