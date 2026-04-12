#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> tab(h,vector<char>(w));
  vector<int> r;
  vector<int> c;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>tab.at(i).at(j);
    }
  }

  int cnt=0;
  
  for(int i=0;i<h;i++){
    cnt=0;
    for(int j=0;j<w;j++){
      if(tab.at(i).at(j)=='.') cnt++;
    }
  if(cnt!=w) r.push_back(i);
  }

  for(int i=0;i<w;i++){
    cnt=0;
    for(int j=0;j<h;j++){
      if(tab.at(j).at(i)=='.') cnt++;
    }
  if(cnt!=h) c.push_back(i);
  }

  for(int x:r){
    cnt=0;
    for(int y:c){
      if(cnt==c.size()-1) {
        cout<<tab.at(x).at(y)<<endl;
        break;
      }
      cout<<tab.at(x).at(y);
      cnt++;
    }
      
  }
  return 0;
}

