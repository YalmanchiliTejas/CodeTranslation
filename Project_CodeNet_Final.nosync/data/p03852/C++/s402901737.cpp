#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string alphabet;
  cin >> alphabet;
  
  if (alphabet == "a" || alphabet == "e" || alphabet == "i" || alphabet == "o" || alphabet == "u"){
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}