#include<cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int main(){
  int n;
  int a[26];
  int m[26];
  string ans;
  for (int i=0;i<26;i++){
    a[i]=0;
    m[i]=50;}
  string s;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>s;
    for (int j=0;j<s.size();j++){
      int t;
      t=s[j]-'a';
      a[t]+=1;
    }
    for (int j=0;j<26;j++){
      if (a[j]<m[j])m[j]=a[j];
      a[j]=0;
    }
  }
  for (int i=0;i<26;i++){
    char c;
    c='a'+i;
    ans=ans+string(m[i],c);
  }
  cout<<ans;
  return 0;
}
      
  
