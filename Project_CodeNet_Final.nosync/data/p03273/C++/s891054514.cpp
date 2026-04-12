#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  vector<vector<char>>f(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>f.at(i).at(j);
    }
  }
  for(int i=0;i<h;i++){
    bool a=true;
    for(int j=0;j<w;j++){
      if(f.at(i).at(j)=='#'){
        a=false;
        break;
      }
    }
    if(a){
      for(int j=0;j<w;j++){
        f.at(i).at(j)='*';
      }
    }
  }
  for(int i=0;i<w;i++){
    bool a=true;
    for(int j=0;j<h;j++){
      if(f.at(j).at(i)=='#'){
        a=false;
        break;
      }
    }
    if(a){
      for(int j=0;j<h;j++){
        f.at(j).at(i)='*';
      }
    }
  }
  for(int i=0;i<h;i++){
    bool ex=false;
    for(int j=0;j<w;j++){
      if(f.at(i).at(j)=='*')continue;
      cout <<f.at(i).at(j);
      ex=true;
    }
    if(ex)cout <<endl;
  }
  cout <<endl;
}