#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int dx[2]={1,0};
int dy[2]={0,1};

ll h,w;
char a[10][10];


void dfs(int x,int y){
  a[x][y]='.';
  for(int i=0;i<2;i++){
    if(a[x+dx[i]][y+dy[i]]=='#'){
      dfs(x+dx[i],y+dy[i]);
      return;
    }

  }

}
int main(){

  cin>>h>>w;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }


  dfs(0,0);

  bool flag=true;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#')flag=false;
    }
  }
  if(flag)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;

  // for(int i=0;i<h;i++){
  //   for(int j=0;j<w;j++){
  //     cout<<a[i][j];
  //   }
  //   cout<<endl;
  // }

  return 0;
}
