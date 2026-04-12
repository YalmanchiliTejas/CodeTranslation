#include <iostream>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  char a;int gr[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a;
      if(a=='.'){
        gr[i][j]=1;
      }else{
        gr[i][j]=0;
      }
    }
  }
  int m=0,gr2[h][w];
  int gy[h],re[w];
  fill(gy,gy+h,0);
  fill(re,re+w,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      m+=gr[i][j];
    }
    if(m==w){
      gy[i]=1;
    }
    m=0;
  }
  m=0;
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      m+=gr[j][i];
    }
    if(m==h){
      re[i]=1;
    }
    m=0;
  }
  for(int i=0;i<h;i++){
    if(gy[i]==0){
      for(int j=0;j<w;j++){
        if(re[j]==0){
          if(gr[i][j]==0){
            cout << '#';
          }else{
            cout << '.';
          }
        }
      }
      cout << endl;
    }
  }
}