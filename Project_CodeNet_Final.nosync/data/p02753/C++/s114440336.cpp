#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,ans("No");
  
  cin >> s;
  for(int i = 0;i<s.length()-1;i++){
    if(s.at(i) != s.at(i+1)){
      ans = "Yes";
      break;
    }
  }
  
  cout << ans << endl;
}