#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char character;
  cin >> character;

  if ((character == 'a') || (character == 'e') || (character == 'i') || (character == 'o') || (character == 'u')) {
    cout << "vowel" << endl;
  } else {
  cout << "consonant" << endl;
  }
}