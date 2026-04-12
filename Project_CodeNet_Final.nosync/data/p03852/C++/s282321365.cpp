#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  if ("aeiou"s.find(c) != string::npos)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}
