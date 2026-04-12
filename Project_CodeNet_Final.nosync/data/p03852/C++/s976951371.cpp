#include <bits/stdc++.h>
using namespace std;

int main() {
  string c;
  cin >> c;

  for(int i = 0; i < c.size(); i++)
  {
    if(c.at(i) == 'a' || c.at(i) == 'i' || c.at(i) == 'u' || c.at(i) == 'e' || c.at(i) == 'o')
      cout << "vowel" << endl;
    else
      cout << "consonant" << endl;
  }
}