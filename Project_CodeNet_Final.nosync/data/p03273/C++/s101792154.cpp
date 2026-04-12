#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a.at(i).at(j);
    }
  }
  vector<bool> H(h,true);
  vector<bool> W(w,true);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#'){
        H.at(i)=false;
        W.at(j)=false;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(H.at(i))continue;
    for(int j=0;j<w;j++){
      if(W.at(j))continue;
      cout<<a.at(i).at(j);
    }
    cout<<endl;
  }
  return 0;
}