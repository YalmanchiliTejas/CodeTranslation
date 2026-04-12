#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  map<char,int> m,a;
  string s;
  cin>>n>>s;
  for(int i=0;i<s.length();++i)a[s[i]]++;
  for(int i=1;i<n;++i){
    cin>>s;
    m.clear();
    for(int j=0;j<s.length();++j)m[s[j]]++;
    for(auto itr=a.begin();itr!=a.end();++itr){
      if(itr->second==0)continue;
      itr->second=min(itr->second,m[itr->first]);
    }
  }
  for(char i='a';i<='z';++i)for(int j=0;j<a[i];++j)cout<<i;
  cout<<"\n";
  return 0;
}