#include<bits/stdc++.h>
using namespace std;
int h,w;
char a[10][10];
int f;

void dfs(int x=0,int y=0){
  //cout<<x<<" "<<y<<endl;
  a[x][y]='.';
  if(x==h-1&&y==w-1)return;
  if(x==h-1){
    if(a[x][y+1]=='.'){
      f=1;
      return;
    }
    dfs(x,y+1);
    return;
  }
  if(y==w-1){
    if(a[x+1][y]=='.'){
      f=1;
      return;
    }
    dfs(x+1,y);
    return;
  }
  if(a[x+1][y]=='#'){
    dfs(x+1,y);
    return;
  }
  if(a[x][y+1]=='#'){
    dfs(x,y+1);
    return;
  }
  f=1;
  return;
}

int main(){
  cin>>h>>w;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>a[i][j];

  dfs();

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(a[i][j]=='#')f=1;

  if(f)cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
  
  return 0;
}
