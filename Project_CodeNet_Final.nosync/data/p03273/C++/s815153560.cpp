#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>>a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) cin>>a[i][j];
  }
  vector<bool>gyo(h);
  vector<bool>row(w);
  for(int i=0;i<h;i++) gyo[i]=false;
  for(int i=0;i<w;i++) row[i]=false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') gyo[i]=true;
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(a[i][j]=='#') row[j]=true;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(gyo[i] && row[j]) cout<<a[i][j];
      if(j==w-1) cout<<endl;
    }
  }
}
