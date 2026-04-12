#include <bits/stdc++.h>

using namespace std;

int main()
{
  char c;

  cin >> c;

  bool vowel = false;

  if (c == 'a')
  {
    vowel = true;
  }
  else if (c == 'i')
  {
    vowel = true;
  }
  else if (c == 'u')
  {
    vowel = true;
  }
  else if (c == 'e')
  {
    vowel = true;
  }
  else if (c == 'o')
  {
    vowel = true;
  }

  printf(vowel ? "vowel" : "consonant");
}