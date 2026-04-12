#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  string str;
  cin >> str;

  if(str == "a" || str == "i" || str == "u" || str == "e" || str == "o")
    cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}