#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < W; j++){
      if(a.at(i).at(j)=='#'){
        break;
      }else{
        if (j == W-1){
          a.erase(a.begin()+i);
          i--;
        }
      }
    }
  }
  for (int j = 0; j < a.at(0).size(); j++) {
    for (int i = 0; i < a.size(); i++){
      if(a.at(i).at(j)=='#'){
        break;
      }else{
        if (i == a.size()-1){
          for(int k = 0; k < a.size(); k++)  a.at(k).erase(a.at(k).begin()+j);
          j--;
        }
      }
    }
  }
  
  for(int i = 0; i<a.size(); i++){
    for(int j=0; j<a.at(0).size(); j++){
      cout << a.at(i).at(j);
      if(j == a.at(0).size()-1) cout << endl;
    }
  }
}

