#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  int cnt=0,row[H],col[W];
  char c[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>c[i][j];
      row[i]=0;
      col[j]=0;
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(c[i][j]=='.') cnt++;
    }
    if(cnt==W) row[i]=1;
    cnt=0;
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(c[i][j]=='.') cnt++;
    }
    if(cnt==H) col[j]=1;
    cnt=0;
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(row[i]==1||col[j]==1) continue;
      else cout<<c[i][j];
    }
    if(row[i]==0)cout<<endl;
  }
}