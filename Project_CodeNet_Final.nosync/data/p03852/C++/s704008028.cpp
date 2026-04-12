#include<iostream>
#include<string>
#include<set>
using namespace std;

int main () {
  char c;
  cin >> c;
  set<char> vowel = {'a', 'i', 'u', 'e', 'o'}; 
  
  cout << (vowel.count(c) > 0 ? "vowel" : "consonant") << endl;
}