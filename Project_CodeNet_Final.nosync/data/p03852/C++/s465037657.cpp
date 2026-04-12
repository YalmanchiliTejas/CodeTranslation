#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  cin >> a;
  
  int sum = 1;

  if ((a == 'a') || (a == 'i') || (a == 'u') || (a == 'e') || (a == 'o')) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  
  return 0;
}

