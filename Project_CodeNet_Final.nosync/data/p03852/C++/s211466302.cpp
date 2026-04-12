#include <bits/stdc++.h>
using namespace std;
    
int main() {
  char boin;
  cin >> boin;

  if ( boin == 'a' || boin == 'e' || boin == 'i' || boin == 'o' || boin == 'u')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}