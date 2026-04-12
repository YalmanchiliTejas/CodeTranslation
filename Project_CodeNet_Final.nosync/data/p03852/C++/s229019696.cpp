#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  char c;
  cin >> c;
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    cout << "vowel" << flush;
  else
    cout << "consonant" << flush;
  return 0;
}
