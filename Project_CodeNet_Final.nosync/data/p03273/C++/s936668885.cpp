#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> grid;
  string whi(w,'.');
  string tmp;
  for(int i=0; i<h; i++){
    cin >> tmp;
    if(tmp==whi){continue;}
    else{grid.push_back(tmp);}
  }
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<w; j++){
      if(grid.at(i).at(j)=='#'){
        //cout << "debug" << endl;
        whi.at(j)='#';
      }
    }
  }
  //cout << whi << endl;
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<w; j++){
      if(whi.at(j)=='#'){
        cout << grid.at(i).at(j);
      }
    }
    cout << endl;
  }
  return 0;
}
  