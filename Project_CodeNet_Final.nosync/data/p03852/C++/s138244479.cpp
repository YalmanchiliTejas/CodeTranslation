#include <bits/stdc++.h>
using namespace std;

int main() {
  string V;
  char S;
  V = "aiueo";
  cin >> S;
  if (V.find(S) != string::npos ) {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
 
}