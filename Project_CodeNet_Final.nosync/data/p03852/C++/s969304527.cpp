#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  string A;
  cin >> str;

    if (str == "a" || str == "i" || str == "u" || str == "e" || str == "o") {
      A = "vowel";
    }
      else {
      A = "consonant";
    }

  
  cout << A << endl;
}