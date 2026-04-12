#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string str = "aeiou";
  
  for (int i = 0; i < str.size(); i++) {
    if (c == str.at(i)) {
      cout << "vowel" << endl;
      break;
    }
    else if (i == str.size() - 1)
      cout << "consonant" << endl;
  }   
}