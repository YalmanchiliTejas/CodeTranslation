#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
  vector<string> vowel = {"a","i","u","e","o"};
  string s;
  
  cin >> s;
  
  cout << (vowel.end() == find(vowel.begin(),vowel.end(),s) ? "consonant" : "vowel") << endl;
  
  return 0;
}
  
  