#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string vowel = "aiueo";
  string ans = "consonant";
  
  for (int i=0; i<5; i++){
	if (c == vowel.at(i) ){
	    ans = "vowel";
    	break;
    }
  }
  cout << ans;

}

