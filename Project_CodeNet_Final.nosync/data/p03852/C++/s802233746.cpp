#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans;
  vector<string> vo ={"a","i","u","e","o"};

  ans = "consonant";
  cin >> s;
  for (int i=0;i<5;i++){
	if (vo.at(i) == s){
	  ans = "vowel";
    }
  }
  cout << ans << endl;
  
}