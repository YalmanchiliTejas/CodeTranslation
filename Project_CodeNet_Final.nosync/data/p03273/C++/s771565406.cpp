#include <bits/stdc++.h>
using namespace std;
int main(void){
  int H,W;
  cin >>H>>W;
  char a[H][W];
  int i, j;
  char tmp;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      cin>>tmp;
      if(tmp=='#')  a[i][j]='#';
      else  a[i][j]='.';
    }
  }
  int row_black[H], ary_black[W];
  for(i=0;i<H;i++){
    row_black[i]=0;
  }
  for(i=0;i<W;i++){
    ary_black[i]=0;
  }
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if (a[i][j]=='#') row_black[i]=1;
    }
  }
  for(j=0;j<W;j++){
    for(i=0;i<H;i++){
      if (a[i][j]=='#') ary_black[j]=1;
    }
  }
  for(i=0;i<H;i++){
    int flag=0;
    for(j=0;j<W;j++){
      if (row_black[i]==1 && ary_black[j]==1){
        cout<<a[i][j];
        flag=1;
      }
    }
    if(flag)  cout<<'\n';
  }
}
