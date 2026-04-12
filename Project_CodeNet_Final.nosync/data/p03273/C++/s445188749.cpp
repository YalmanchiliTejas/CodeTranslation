#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >>h>>w;
  vector<vector<char>>a(h,vector<char>(w));
  vector<bool>tate(h);
  vector<bool>yoko(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    yoko[i]=true;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        yoko[i]=false;
        break;
      }
    }
  }
  for(int j=0;j<w;j++){
    tate[j]=true;
    for(int i=0;i<h;i++){
      if(a[i][j]=='#'){
        tate[j]=false;
        break;
      }
    }
  } 
  for(int i=0;i<h;i++){
    if(yoko[i]==true)continue;
    for(int j=0;j<w;j++){
      if(tate[j]==true)continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
  return 0;
}
  