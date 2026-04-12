#include <bits/stdc++.h>
using namespace std;

int main() {
  const string vowels= "aeiou";
  char c;
  cin >> c;
  auto res= find(vowels.begin(), vowels.end(), c);
  if(res!=vowels.end()){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }
}