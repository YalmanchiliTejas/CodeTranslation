#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<vector<int>> s(n,vector<int>(26,0));

  for(int i=0; i<n; ++i){
    string t; cin>>t;
    for(char x:t)++s[i][x-'a'];
  }

  vector<int> a(26,100);
  for(int i=0; i<26; ++i){
    for(int j=0; j<n; ++j){
      a[i]=min(a[i],s[j][i]);
    }
  }

  for(int i=0; i<26; ++i){
    for(int j=0; j<a[i]; ++j)cout<<char('a'+i);
  }
  cout<<endl;
}
