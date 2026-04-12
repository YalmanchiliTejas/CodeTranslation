#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string ans = "No";
  for(int i = 0 ; i < s.size() - 1 ; i++){
    if(s.substr(i, 2) == "AC"){
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}