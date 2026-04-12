#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;
  cin >> s;
  
  bool ans = true;
  if(s[0] == s[1] && s[1] == s[2]){
    ans = false;
  }
  
  if(ans){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}