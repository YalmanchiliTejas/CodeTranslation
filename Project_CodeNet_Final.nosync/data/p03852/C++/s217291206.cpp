#include <iostream>
#include <string>
using namespace std;

int main(){
  string s = "aeiou";
  char c;
  cin >> c;
  for(int i = 0; i < 5; ++i){
	if(c == s[i]){
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
