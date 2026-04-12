#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;cin>>n;
  vector<int>hm(26,0);
  string s;cin>>s;
  for(int i=0;i<s.size();i++)hm[s[i]-'a']++;
  for(int i=1;i<n;i++){
    string t;cin>>t;
    vector<int> gm(26,0);
    for(int j=0;j<t.size();j++)gm[t[j]-'a']++;
    for(int j=0;j<26;j++){
      hm[j]=min(hm[j],gm[j]);
    }
  }
  string ans="";
  for(int i=0;i<26;i++){
    for(int j=0;j<hm[i];j++){
      char c='a'+i;
      ans+=c;
    }
  }
  cout<<ans<<endl;
}