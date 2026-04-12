#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  string str = "aiueo";
  string ans = "consonant";
  
  cin >> c;
  
  for(int i = 0; i < str.size(); i++){
    if(c == str.at(i)){
      ans = "vowel";
      break;
    }
	
  }
  
  cout << ans << endl;
  
}