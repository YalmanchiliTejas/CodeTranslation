#include <bits/stdc++.h>
using namespace std;

int main() {
  string c;
  cin >> c;
  char b = c.at(0);
  if ( b == 'a' || b == 'i' || b == 'u' || b == 'e' || b == 'o'){
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
