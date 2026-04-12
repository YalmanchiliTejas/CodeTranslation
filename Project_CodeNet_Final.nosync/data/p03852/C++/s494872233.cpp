#include <bits/stdc++.h>
using namespace std;

int main()
{
  char object;
  cin >> object;
  int flag_vowel = 0;
  switch (object)
  {
  case 'a':
    flag_vowel = 1;
  case 'i':
    flag_vowel = 1;
  case 'u':
    flag_vowel = 1;
  case 'e':
    flag_vowel = 1;
  case 'o':
    flag_vowel = 1;
  }
  if (flag_vowel == 1)
  {
    cout << "vowel" << endl;
  }
  else
  {
    cout << "consonant" << endl;
  }
}