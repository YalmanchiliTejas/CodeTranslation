#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> ans(26,100);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    vector<int> cnt(26);
    for(int j = 0; j < s.size(); j++){
      int idx = s[j] - 'a';
      cnt[idx]++;
    }
    for(int j = 0; j < 26; j++){
      ans[j] = min(ans[j], cnt[j]);
    }
  }
  for(int i = 0; i < 26; i++){
    char c = 'a' + i;
    for(int j = 0; j < ans[i]; j++){
      cout << c;
    }
  }
}
    
    