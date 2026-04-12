
#include <iostream>
using namespace std;

int main()
{
  int vowel['a' + 26] = {};
  vowel['a'] = 1;
  vowel['e'] = 1;
  vowel['i'] = 1;
  vowel['o'] = 1;
  vowel['u'] = 1;
  char c;
  cin >> c;
  cout << ((1 == vowel[c]) ? "vowel" : "consonant");
  return 0;
}
