#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool ans = false;
  for(int i=1; i<s.length(); i++){
    if(s[i-1] != s[i]){
      ans = true;
      break;
    }
  }
  ans ? cout<<"Yes\n" : cout<<"No\n";
  return 0;
}