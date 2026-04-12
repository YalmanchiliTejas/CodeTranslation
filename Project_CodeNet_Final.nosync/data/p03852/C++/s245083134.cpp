#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  if  (str == "a" || str == "e" || str == "i" || str == "o" || str == "u")
    cout << "vowel";
  else
    cout << "consonant";
}
