#include <iostream>
#include <regex>
#include <locale>

using namespace std;

int main() {
  string s;
  cin >> s;
  regex re("AAA|BBB");
  if ( regex_match(s, re) ) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}