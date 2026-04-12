#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w,'0'));
  vector<int> dh(h);
  vector<int> dw(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) cin>>a.at(i).at(j);
  }
  for(int i=0;i<h;i++){
    int cnt=0;
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='.') cnt++;
    }
    if(cnt==w) dh.at(i)=1;
  }
  for(int i=0;i<w;i++){
    int cnt=0;
    for(int j=0;j<h;j++){
      if(a.at(j).at(i)=='.') cnt++;
    }
    if(cnt==h) dw.at(i)=1;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dh.at(i)==0 && dw.at(j)==0) cout<<a.at(i).at(j);
    }
    if(dh.at(i)==0) cout<<endl;
  }
}