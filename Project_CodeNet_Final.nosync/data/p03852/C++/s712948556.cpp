#include <iostream>
using namespace std;

int main(){
  char c;
  cin >> c;
  cout << ((c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ? "vowel" : "consonant") << endl;
}