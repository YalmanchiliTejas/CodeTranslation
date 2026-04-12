#include<bits/stdc++.h>
using namespace std;
int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<a.size();){
    bool flag=true;
    for(int j=0;j<a[0].size();j++){
      if(a[i][j]=='#') flag=false;
    }
    if(flag) {
      a.erase(a.begin()+i);
      continue;
    }
    i++;
  }
  for(int i=0;i<a[0].size();){
    bool flag=true;
    for(int j=0;j<a.size();j++){
      if(a[j][i]=='#') flag=false;
    }
    if(flag) {
      for(int j=0;j<a.size();j++){
        a[j].erase(a[j].begin()+i);
      }
      continue;
    }
    i++;
  }
  for(auto &e:a){
    for(auto &i:e) cout<<i;    
    cout<<endl;
  }
}