#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  char c[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c[i][j];
    }
  }
  for(int i=0;i<w;i++){
    bool a=true;
    for(int j=0;j<h;j++){
      if(c[j][i]=='#')
        a=false;
    }
    if(a){
      for(int j=0;j<h;j++){
        c[j][i]='%';
      }
    }
  }
  for(int i=0;i<h;i++){
    bool a=true;
    for(int j=0;j<w;j++){
      if(c[i][j]=='#')
        a=false;
    }
    if(a){
      c[i][0]='d';
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(c[i][j]=='d')
        break;
      else if(c[i][j]!='%')
        cout<<c[i][j];
    }
    cout<<endl;
  }
}
