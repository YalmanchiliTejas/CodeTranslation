#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  vector<int> ans(26,-1);
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    vector<int> tmp(26, -1);
    for(int j=0; j<s.length(); j++){
      if(tmp[s[j]-'a'] == -1) tmp[s[j]-'a'] = 1;
      else tmp[s[j]-'a'] += 1;
    }
    if(i==0){
      for(int k=0; k<26; k++){
        ans[k] = tmp[k];
      }
      continue;
    }
    for(int k=0; k<26; k++){
      if(ans[k] == -1) continue;
      if(tmp[k] == -1) ans[k] = -1;
      else ans[k] = min(ans[k], tmp[k]);
    }
  }
  for(int i=0; i<26; i++){
    if(ans[i] == -1) continue;
    for(int j=0; j<ans[i]; j++){
      cout << string({'a'+i});
    }
  }
  cout << endl;
  return 0;
  
}
