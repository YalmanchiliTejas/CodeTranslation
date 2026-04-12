#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> a.at(i).at(j);
    }
  }

  set<int> hd, wd;
  for(int i=0; i<h; i++){
    bool flg=true;
    for(char x:a.at(i)){
      if(x=='#'){
        flg=false;
        break;
      }
    }
    if(flg){
      hd.insert(i);
    }
  }

  for(int i=0; i<w; i++){
    bool flg=true;
    for(int j=0; j<h; j++){
      if(a.at(j).at(i)=='#'){
        flg=false;
        break;
      }
    }
    if(flg) wd.insert(i);
  }

  for(int i=0; i<a.size(); i++){
    if(hd.find(i)!=hd.end()) continue;
    for(int j=0; j<a.at(0).size(); j++){
      if(wd.find(j)!=wd.end()) continue;
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
