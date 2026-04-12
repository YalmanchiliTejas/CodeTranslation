#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char a[H][W];
  int line[H]={},column[W]={};
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<H;i++){
    bool flag = 0;
    for(int j=0;j<W;j++){
      if(a[i][j]=='#'){
        flag = 1;
        break;
      }
    }
    if(!flag)
      line[i]++;
  }
  for(int i=0;i<W;i++){
    bool flag = 0;
    for(int j=0;j<H;j++){
      if(a[j][i]=='#'){
        flag = 1;
        break;
      }
    }
    if(!flag)
      column[i]++;
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(line[i]!=1&&column[j]!=1)
       cout <<  a[i][j];
    }
    if(line[i]!=1)
    	cout << endl;
  }
}