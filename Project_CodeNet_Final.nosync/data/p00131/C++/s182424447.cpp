#include<iostream>
using namespace std;
int I,flg;
int t[10][10],u[10][10];
int ans[10][10];
void check();
void dfs(int);
void compute(int,int);
int main(){
  cin>>I;
  while(I--){
    flg=0;
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	cin>>t[i][j];
	u[i][j]=t[i][j];
	ans[i][j]=0;
      }
    }
    dfs(0);
  }
  return 0;
}


void dfs(int x){
  if(flg)return;
  if(x==10){
    check();
  }else{
    ans[0][x]=0;
    dfs(x+1);
    if(flg)return;
    ans[0][x]=1;
    dfs(x+1);
  }
}


void check(){
  if(flg)return;
  for(int i=0;i<10;i++)for(int j=0;j<10;j++)t[i][j]=u[i][j];

  for(int i=0;i<10;i++)if(ans[0][i]==1)compute(0,i);
  
  for(int i=1;i<10;i++){
    for(int j=0;j<10;j++){
      ans[i][j]=0;
      if(t[i-1][j]==1){
	ans[i][j]=1;
	compute(i,j);
      }
    }
  }
  /*
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(j)cout<<' ';
      cout<<t[i][j];
    }
    cout<<endl;
  }
  */
  int cnt=0;
  for(int i=0;i<10;i++)cnt+=t[9][i];
  if(cnt==0){
    flg=1;
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	if(j)cout<<' ';
	cout<<ans[i][j];
      }
      cout<<endl;
    }
  }
}

void compute(int y,int x){
  t[y][x]=(t[y][x]*-1)+1;
  if(y>0)t[y-1][x]=(t[y-1][x]*-1)+1;
  if(x>0)t[y][x-1]=(t[y][x-1]*-1)+1;
  if(y<9)t[y+1][x]=(t[y+1][x]*-1)+1;
  if(x<9)t[y][x+1]=(t[y][x+1]*-1)+1;
}