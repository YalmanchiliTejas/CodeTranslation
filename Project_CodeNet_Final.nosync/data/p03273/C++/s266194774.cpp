#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i) = 0; (i) <(n); (i)++) 
using ll = long long;
int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<string>> a(h,vector<string>(w));
  char k;
  rep(i,h){
    rep(j,w){
      cin>>k;a.at(i).at(j)=k;
    }
  }
  rep(i,h){
    bool t=true;
    rep(j,w){
      if(a.at(i).at(j)!=".")t=false;
    }
    if(t){
      rep(j,w)a.at(i).at(j)="";
    }
  }
  rep(j,w){
    bool t=true;
    rep(i,h){
      if(a.at(i).at(j)!="."&&a.at(i).at(j)!="")t=false;
    }
    if(t){
      rep(i,h)a.at(i).at(j)="";
    }
  }
  
  rep(i,h){
    int l=0;
    rep(j,w){
      cout<<a.at(i).at(j);
    }
    rep(j,w){
      if(a.at(i).at(j)=="."||a.at(i).at(j)=="#")l++;
    }
    if(l>0){
      cout<<endl;
    }
    
  }
}