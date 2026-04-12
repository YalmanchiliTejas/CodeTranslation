#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> alp(26,0);
  
  for(int i=0;i<n;i++){
    string s; cin>>s;
    vector<int> now(26);
    for(int j=0;j<(int)s.size();j++){
      now[s[j]-'a']++;
    }
    if(i==0){
      for(int j=0;j<26;j++){
      	alp[j]=now[j];
      }
    }else{
      for(int j=0;j<26;j++){
        alp[j]=min(alp[j],now[j]);
      }
    }
  }
  
  for(int i=0;i<26;i++){
    cout<<string(alp[i], (char)(i+'a'));
  }
  
  cout<<endl;
  return 0;
}