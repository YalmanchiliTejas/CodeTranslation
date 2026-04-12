#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; i++) cin >> s[i];
 
  map<int, int> mp;
  for(int i=0; i<26; i++){
    mp[i] = 0;
  }
  for(int i=0; i<s[0].size(); i++) mp[s[0][i]-'a']++;
  for(int i=1; i<n; i++){
    map<int,int> num;
    for(int j=0; j<26; j++){
      num[j] = 0;
    }
    for(int j=0; j<s[i].size(); j++){
      num[s[i][j]-'a']++;
    }
    for(int j=0; j<26; j++){
      mp[j] = min(mp[j], num[j]);
    }
  }
  string ss = "";
  for(int i=0; i<26; i++){
    if(mp[i]>0){
      for(int j=0; j<mp[i]; j++){
        ss += i+'a';
      }
    }
  }
  cout << ss << endl;
}