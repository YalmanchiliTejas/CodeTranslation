#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
  char word;
  cin >> word;
  
  if ((word == 'a') || (word == 'i') ||( word == 'u') || (word == 'e') || (word == 'o')) 
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  return (0);
}