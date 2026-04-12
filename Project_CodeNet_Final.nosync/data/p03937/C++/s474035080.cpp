#include <bits/stdc++.h>
using namespace std;
bool mp[10][10];
int h,w;

void dfs(int i,int j){
  if(mp[i][j]==0) return;
  mp[i][j]=0;
  if(mp[i+1][j]) return dfs(i+1,j);
  return dfs(i,j+1);
}

int main(){
  cin>>h>>w;
  string s;
  for(int i=0;i<h;i++){
    cin>>s;
    for(int j=0;j<w;j++)
      mp[i][j]=(s[j]!='.');
  }
  dfs(0,0);
  bool f=0;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(mp[i][j]){f=1;break;}
  if(f)cout<<"Impossible";
  else cout<<"Possible";
  cout<<endl;
  return 0;
}
