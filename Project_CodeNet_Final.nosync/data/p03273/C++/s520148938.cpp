#include <bits/stdc++.h>
using namespace std;
int main() {
  int h,w; cin>>h>>w;
  int r[h]={0},c[w]={0};
  char a[h][w];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin>>a[i][j];
      if(a[i][j]=='#') r[i]++,c[j]++;
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(r[i]&&c[j]) cout<<a[i][j];
    }
    if(r[i]) cout<<endl;
  }
}