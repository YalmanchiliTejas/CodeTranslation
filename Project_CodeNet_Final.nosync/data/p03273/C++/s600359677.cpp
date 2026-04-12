#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  string mp[h];
  for(int i=0;i<h;++i){
    cin>>mp[i];
  }
  string white;
  for(int i=0;i<mp[0].size();++i) white+='.';
  for(int i=0;i<h;++i){
    if(mp[i]==white){
      for(int j=0;j<mp[i].size();++j) mp[i][j]='@';
    }
  }
  for(int i=0;i<mp[0].size();++i){
    bool flag=true;
    for(int j=0;j<h;++j){
      if(mp[j][i]=='#') flag=false;
    }
    if(flag){
      for(int j=0;j<h;++j) mp[j][i]='@';
    }
  }
  for(int i=0;i<h;++i){
    int cnt=0;
    for(int j=0;j<mp[i].size();++j){
      if(mp[i][j]!='@'){ cout<<mp[i][j]; ++cnt; }
    }
    if(cnt) cout<<endl;
  }
  return 0;
}
