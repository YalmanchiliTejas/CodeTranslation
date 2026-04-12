#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  string s;cin>>s;
  int m;cin>>m;
  for(int i=0;i<s.size();i++){
    if(s[i]!=s[m-1])cout<<'*';
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}