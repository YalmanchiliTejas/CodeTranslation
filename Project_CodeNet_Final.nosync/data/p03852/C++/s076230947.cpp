#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  
  cin >> S;
  
  if (S == "a" || S == "e" || S == "i" || S == "u" || S == "o")
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}
