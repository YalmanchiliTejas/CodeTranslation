#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s[n],t="";
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<s[0].size();i++){
    char c=s[0][i];
    bool f=true;
    for(int j=1;j<n;j++){
      bool ff=true;
      for(int k=0;k<s[j].size();k++){
        if(c==s[j][k]){
          ff=false;
          break;
        }
      }
      if(ff){
        f=false;
        break;
      }
    }
    if(f){
      for(int j=1;j<n;j++){
        for(int k=0;k<s[j].size();k++){
          if(c==s[j][k]){
            s[j][k]='#';
            break;
          }
        }
      }
      t.push_back(c);
    }
  }
  sort(t.begin(),t.end());
  cout<<t;
}