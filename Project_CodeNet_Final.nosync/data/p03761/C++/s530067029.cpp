#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a[26];
  cin>>n;
  for(int i=0;i<26;++i)a[i]=1e9;
  for(int i=0;i<n;++i){
    string s;
    cin>>s;
    int b[26]={};
    for(int j=0;j<s.size();++j){
        b[s[j]-'a']++;
    }
    for(int j=0;j<26;++j){
        a[j]=min(a[j],b[j]);
    }
  }
  for(int i=0;i<26;++i){
    if(a[i]==1e9)continue;
    for(int j=0;j<a[i];++j){
        cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
