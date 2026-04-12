#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  char c;
  string s = "aeiou";

  cin >> c;

  if(s.find(c) != string::npos) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
