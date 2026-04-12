#include<iostream>
#include<string>
using namespace std;
int main()
{
  string c;
  cin >> c;
  if((c == "a") || (c == "i") || (c == "e") || (c == "u") || (c == "o"))
    cout << "vowel";
  else cout << "consonant";
  return 0;
}