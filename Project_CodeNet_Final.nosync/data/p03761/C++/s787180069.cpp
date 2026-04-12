#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<string>s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  vector<int>num(26);
  for(int i=0;i<26;i++) num[i]=50;
  for(int i=0;i<n;i++){
    vector<int>sub(26);
    int l=s[i].size();
    for(int j=0;j<l;j++) sub[s[i][j]-'a']++;
    for(int j=0;j<26;j++) num[j]=min(num[j],sub[j]);
  }
  for(int i=0;i<26;i++){
    char x='a'+i;
    for(int j=0;j<num[i];j++) cout<<x;
  }   
}