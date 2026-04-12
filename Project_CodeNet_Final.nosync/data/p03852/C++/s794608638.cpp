#include <iostream>
#include <regex>
using namespace std;

int main(){
	string c;
  regex r("[aiueo]");

	cin >> c;

  if(regex_match(c, r)) cout << "vowel" << endl;
  else cout << "consonant" << endl;
	
}