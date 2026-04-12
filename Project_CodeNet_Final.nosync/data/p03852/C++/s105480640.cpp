#include <bits/stdc++.h>
using namespace std;

int main() {
  string vowel = "aeiou";
  char c;
  cin >> c;

  if (vowel.find(c) == std::string::npos ) cout << "consonant" << endl;
  else cout << "vowel" << endl;

return 0;

}