#include<iostream>
using namespace std;
int n,m,o,a,b,c,d;
int t[15][15];
 
 
void rotate(int y,int x,int size,int angle){
  y--;x--;
  int u[15][15];
  int v[15][15];
 
  angle/=90;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      u[i][j]=t[y+i][x+j];
    }
  }
  while(angle--){
 
    for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
    v[j][size-1-i]=u[i][j];
      }
    }
 
    for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
    u[i][j]=v[i][j];
      }
    }
 
  }//while
 
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      t[i+y][j+x]=u[i][j];
    }
  }
}
 
void reversal(int y,int x,int size){
  y--;x--;
 
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      t[y+i][x+j]=1-t[y+i][x+j];
    }
  }
}
 
void lefts(int y){
  y--;
  int tmp=t[y][0];
  for(int i=0;i<n-1;i++)t[y][i]=t[y][i+1];
  t[y][n-1]=tmp;
}
 
void rights(int y){
  y--;
  int tmp=t[y][n-1];
  for(int i=n-1;i>=1;i--)t[y][i]=t[y][i-1];
  t[y][0]=tmp;
}
 
void dfs(int y,int x,int key){
  if(y<0||y>=n)return;
  if(x<0||x>=n)return;
  if(t[y][x]!=key)return;
  t[y][x]=1-key;
  dfs(y+1,x,key);
  dfs(y-1,x,key);
  dfs(y,x+1,key);
  dfs(y,x-1,key);
}
 
void islandr(int y,int x){
  y--;x--;
  dfs(y,x,t[y][x]);
}
 
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>t[i][j];
    }
  }
 
  for(int i=0;i<m;i++){
    cin>>o;
    if(o==0){
      cin>>a>>b>>c>>d;
      rotate(a,b,c,d);
    }else if(o==1){
      cin>>a>>b>>c;
      reversal(a,b,c);
    }else if(o==2){
      cin>>a;
      lefts(a);
    }else if(o==3){
      cin>>a;
      rights(a);
    }else{
      cin>>a>>b;
      islandr(a,b);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j)cout<<' ';
      cout<<t[i][j];
    }
    cout<<endl;
  }
  return 0;
}