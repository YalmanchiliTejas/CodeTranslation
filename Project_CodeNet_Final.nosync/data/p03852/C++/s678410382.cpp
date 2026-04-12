#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string str[5] = {"a", "e", "i", "o", "u"};
int main() {
  string c;
  cin >> c;
  string ans = "consonant";
  rep(i, 5) {
    if (str[i] == c) ans = "vowel";
  }

  cout << ans << endl;

  return 0;
}
