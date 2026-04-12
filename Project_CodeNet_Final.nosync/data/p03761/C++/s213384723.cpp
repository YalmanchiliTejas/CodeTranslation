#include <bits/stdc++.h>
using namespace std;
int alpha[26] , f[26];
signed main(){
  int n;
  string s;
  vector<char> c;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<s.size();j++){
      f[s[j]-'a']++;
    }
    for(int j=0;j<26;j++){
      if(i == 0){
        alpha[j]=100;
      }
      alpha[j]=min(alpha[j],f[j]);
      f[j]=0;
    }
  }
  
  for(int i=0;i<26;i++){
    for(int j=0;j<alpha[i];j++){
      c.push_back(i+'a');
    }
  }
  sort(c.begin(),c.end());
  
  for(int i=0;i<c.size();i++){
    cout<<c[i];
  }
  
  cout<<endl;
  return(0);
}