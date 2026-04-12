#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> a(H);
  set<int> h,w;
  for(int i=0;i<H;i++){
    bool flag=true;
    cin >> a.at(i);
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)!='.'){
        flag=false;
        break;
      }
    }
    if(flag){
      h.insert(i);
    }
  }
  for(int j=0;j<W;j++){
    bool flag=true;
    for(int i=0;i<H;i++){
      if(a.at(i).at(j)!='.'){
        flag=false;
        break;
      }
    }
    if(flag){
      w.insert(j);
    }
  }
  for(int i=0;i<H;i++){
    if(h.count(i)){
      continue;
    }
    for(int j=0;j<W;j++){
      if(w.count(j)){
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}
