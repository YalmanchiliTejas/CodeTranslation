#include<iostream>
#include<string>
using namespace std;
int main(){
  string a;
  cin >> a;
  cout << ((a == "a" || a == "i" || a == "u" || a == "e" || a == "o") ? "vowel":"consonant") << endl;
  return 0;
}