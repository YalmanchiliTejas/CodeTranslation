#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  char ss = S.at(0);
  if (ss == 'a' || ss == 'i' || ss == 'u' || ss == 'e' || ss == 'o')
  {
    cout << "vowel" << endl;
  }
  else
  {
    cout << "consonant" << endl;
  }
}
