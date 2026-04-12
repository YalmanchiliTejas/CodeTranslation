#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<int> a(h);
  vector<int> b(w);
  char x[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      cin>>x[i][j];
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(x[j][i]=='#')
        break;
      if(j==h-1)
        b[i]=1;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(x[i][j]=='#')
        break;
      if(j==w-1)
        a[i]=1;
    }
  }
  for(int i=0;i<h;i++){
    if(a[i]==1)
      continue;
    for(int j=0;j<w;j++){
      if(b[j]==1){
        if(j==w-1)cout<<endl;
        continue;
      }
      cout<<x[i][j];
      if(j==w-1)cout<<endl;
    }
  }
}