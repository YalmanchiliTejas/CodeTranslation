#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)

int main(){
  int h,w;
  cin >> h >> w;
  vector< vector<int> > a;
  
  char tmp;
  rep(i,h){
    vector<int> v;
    rep(j,w){
      cin >> tmp;
      if(tmp=='#') v.push_back(1); 
      else v.push_back(0);
    }
    a.push_back(v);
  }
  
  vector<int> empty_h,empty_w;
  rep(i,h){
    bool empty=true;
    rep(j,w){
      if(a[i][j]==1) empty=false;
    }
    if(empty) empty_h.push_back(i);
  }
  rep(j,w){
    bool empty=true;
    rep(i,h){
      if(a[i][j]==1) empty=false;
    }
    if(empty) empty_w.push_back(j);
  }
  
  reverse(empty_h.begin(),empty_h.end());
  reverse(empty_w.begin(),empty_w.end());
  
  for(int x : empty_h){
    a.erase(a.begin() + x);
  }
  for(int y : empty_w){
    rep(i,a.size()){
      a[i].erase(a[i].begin()+y);
    }
  }
  
  for(vector<int> v : a){
    for(int i : v){
      if(i==1) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
  
  return 0;
}
