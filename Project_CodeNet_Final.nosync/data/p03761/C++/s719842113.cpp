#include<bits/stdc++.h>
using namespace std;
#define long long long

int main(){
  int n;
  cin >> n;
  int num[50][26]={};
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(int j=0; j<s.size(); j++){
      num[i][s[j]-'a']++;
    }
  }
  string ans="";
  for(int j=0; j<26; j++){
    int m=50;
    for(int i=0; i<n; i++){
      m = min(num[i][j],m);
    }
    for(int i=0; i<m; i++){
      ans+=(char)('a'+j);
    }
  }
  cout << ans << endl;
  return 0;
}