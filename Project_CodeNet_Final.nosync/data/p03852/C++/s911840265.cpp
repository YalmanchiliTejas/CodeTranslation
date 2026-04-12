#include <iostream>
#include <string>
using namespace std;
 
int main() {
  char c;
  cin >> c;
  const string vowel = "aeiou";
  vowel.find(c) != string::npos ? (cout <<  "vowel") : (cout << "consonant");
  return 0;
}