#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  vector<int> hantei_h(h,0);
  vector<int> hantei_w(w,0);  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        hantei_h[i]=1;
        break;
      }
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(a[i][j]=='#'){
        hantei_w[j]=1;
        break;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(hantei_h[i]==0)continue;
    for(int j=0;j<w;j++){
      if(hantei_w[j]==1)cout<<a[i][j];
    }
    cout<<endl;
  }  
  return 0;
}