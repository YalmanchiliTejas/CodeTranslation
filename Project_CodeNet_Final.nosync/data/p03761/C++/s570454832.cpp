#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  string s[n];
  vector<char>v={};
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  sort(s[0].begin(),s[0].end());
  if(n==1) cout<<s[0]<<endl;
  else{
    for(int i=0;i<s[0].size();i++){
      bool b=true;
      for(int j=1;j<n;j++){
        if(s[j].find(s[0][i])==string::npos){
          b=false;
          break;
        }
        else s[j].erase(find(s[j].begin(),s[j].end(),s[0][i]));
      }
      if(b) v.push_back(s[0][i]);
    }
    for(int i=0;i<v.size();i++)cout<<v.at(i);
  }
}


