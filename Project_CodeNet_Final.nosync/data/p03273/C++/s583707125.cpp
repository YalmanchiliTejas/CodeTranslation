#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  vector<string> m;
  cin>>h>>w;
  m.resize(h);
  for(int i=0;i<h;i++)cin>>m[i];
  for(int i=0;i<h;i++){
    while(i<m.size()&&find(m[i].begin(),m[i].end(),'#')==m[i].end())m.erase(m.begin()+i);
    h=m.size();
  }
  for(int i=0;i<w;i++){
    bool t=false;
    for(int j=0;j<h;j++)if(m[j][i]=='#')t=true;
    if(!t)for(int j=0;j<h;j++)m[j][i]='x';
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char u=m[i][j];
      if(u=='x')continue;
      cout<<u;
    }
    cout<<endl;
  }
  return 0;
}