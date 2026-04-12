#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  int a = 0;
  cin >> c;

  if (c == 'a') 
    a++;
  else if (c == 'i') 
    a++;
  else if (c == 'u')
    a++;
  else if (c == 'e')
    a++;
  else if (c == 'o')
    a++;

  if (a == 0)
    cout << "consonant";
  else
    cout << "vowel";
}