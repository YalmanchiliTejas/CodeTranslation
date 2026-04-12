#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int h, w; cin >> h >> w;
  vector<vector<char> > v(h, vector<char>(w));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> v[i][j];
    }
  }
  for(int i = 0; i < v.size(); i++){
    int j = 0;
    for(; j < v[i].size(); j++){
      if(v[i][j] != '.') break;
    }
    if(j == v[i].size()){
      v.erase(v.begin() + i);
      i = -1;
      /*cout << endl;
      for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
          cout << v[i][j];
        }
        cout << endl;
      }*/
    }
  }
  int i = 0;
  while(i < v[0].size()){
    int j = 0;
    for(; j < v.size(); j++){
      if(v[j][i] != '.') break;
    }
    if(j == v.size()){
      for(int k = 0; k < v.size(); k++){
        v[k].erase(v[k].begin() + i);
      }
    }
    else i++;
  }




  /*for(int i = 0; i < v[i].size(); i++){
    cout << "v[" << i << "].size: " << v[i].size() << endl;
    int j = 0;
    for(; j < v.size(); j++){
      if(v[j][i] != '.') break;
    }
    if(j == v.size()){
      for(int k = 0; k < v.size(); k++){
        v[k].erase(v[k].begin() + i);
      }
      i = -1;
      cout << endl;
      for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
          cout << v[i][j];
        }
        cout << endl;
      }
    }
    if(i + 1 >= v.size()) break;
  }*/

  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      cout << v[i][j];
    }
    cout << endl;
  }
  return;
}
int main(){
  solve();
  return 0;
}
