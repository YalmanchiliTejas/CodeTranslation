#include <bits/stdc++.h>
using namespace std;

int main() {
  char mozi;
  cin >> mozi;
  
  if (mozi == 'a' || mozi == 'i' || mozi == 'u' || mozi == 'e' || mozi == 'o') {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}