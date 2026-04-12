#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  int i;
  bool b;

  cin >> c;

  char vowel[5] = {'a', 'i', 'u', 'e', 'o'};

  for (i=0;i<5;i++){
    if (c == vowel[i]) {
      b = true;
      break;
    } else {
      b = false;
    }
  }

  if (b) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
      
}