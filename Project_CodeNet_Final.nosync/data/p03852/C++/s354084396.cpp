#include<regex>
#include<iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;
  regex re("a|e|i|o|u");
  string out = regex_match(s, re) ? "vowel" : "consonant";
  cout << out << endl;
}
