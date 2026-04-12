#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >>n;
  vector<string> s(n);
  vector<vector<int> > cnt(26,vector<int>(n,0));
  for(int i=0;i<n;++i){
    cin >> s[i];
    for(int j=0;j<s[i].size();++j) cnt[s[i][j]-'a'][i]++;
  }
  for(int i=0;i<26;++i) {
    for(int j=0;j<*min_element(cnt[i].begin(),cnt[i].end());++j) printf("%c",'a'+i);
  }
  cout <<endl;
  return 0;
}
