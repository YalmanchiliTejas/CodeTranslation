#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  string str = "aeiou"; 
  string msg = "consonant";
  for(int i = 0; i < str.size(); i++) {
    if(str.at(i) == c) {
	  msg = "vowel";
      break;
  	}
  }
  cout << msg << endl;
}
