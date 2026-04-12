#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int h,w;
  cin>>h>>w;
  char a[h][w];
  int b[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      if(a[i][j]=='#') b[i][j]=1;
      else b[i][j]=-1;
    }
  }
  bool flg=1;
  for(int i=0;i<h;i++){
    flg=1;
    for(int j=0;j<w;j++){
      if(b[i][j]==1) flg=0;
    }
    if(flg){
      for(int j=0;j<w;j++){
        b[i][j]=0;
      }
    }
  }
  
  for(int j=0;j<w;j++){
    flg=1;
    for(int i=0;i<h;i++){
      if(b[i][j]==1) flg=0;
    }
    if(flg){
      for(int i=0;i<h;i++){
        b[i][j]=0;
      }
    }
  }
  
  bool flg2=0;
  for(int i=0;i<h;i++){
    flg2=0;
    for(int j=0;j<w;j++){
      if(b[i][j]!=0){
        cout<<a[i][j];
        flg2=1;
      }
    }
    if(flg2) cout<<endl;
  }
  
}