#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;  cin >> n;
  vector<int> cnt(26, 0);
  string s; cin >> s;
  for(int i=0; i<s.size(); i++){
    cnt[s[i]-'a'] += 1;
  }

  for(int i=1; i<n; i++){
    cin >> s;
    vector<int> tmp(26, 0);
    for(int i=0; i<s.size(); i++){
      if(cnt[s[i]-'a']==0) continue;
      tmp[s[i]-'a'] += 1;
    }
    for(int i=0; i<26; i++)
      cnt[i] = min(cnt[i], tmp[i]);
  }
  for(int i=0; i<26; i++)
    for(int j=0; j<cnt[i]; j++){
      printf("%c", i+'a');
    }
  cout << endl;
}
