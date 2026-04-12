#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  char c[h][w];
  bool f[w];
  bool ff[h];
  for(int j=0;j<w;j++){
    f[j]=true;
  }
  for(int i=0;i<h;i++){
    ff[i]=true;
    for(int j=0;j<w;j++){
      cin>>c[i][j];
      if(c[i][j]=='#'){
        f[j]=false;
        ff[i]=false;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(ff[i]) continue;
    for(int j=0;j<w;j++){
      if(f[j]) continue;
      cout<<c[i][j];
    }
    cout<<endl;
  }
}