// B - Grid Compression
//B - Card Game for Two
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> check;
int H, W;
int solve();

int main() {

  cin >> H >> W;
  grid = vector<vector<char>>(H, vector<char>(W));
  check = vector<vector<bool>>(H, vector<bool>(W, true));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> grid.at(i).at(j);
    }
  }

  solve();
}

int solve(){


  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid.at(i).size(); j++){
      if(grid.at(i).at(j) == '#'){
        break;
      }
      if(j == grid.at(i).size() -1){
        // grid.erase(grid.begin() + i);
        for(int k=0; k<grid.at(i).size(); k++){
          check.at(i).at(k) = false;
        }
      }
    }
  }

  for(int j=0; j<grid.at(0).size(); j++){
    for(int i=0; i<grid.size(); i++){
      if(grid.at(i).at(j) == '#'){
        break;
      }

      if(i == grid.size() -1){
        for(int s=0; s<grid.size(); s++){
          // grid.at(s).erase(grid.at(s).begin() + j);
          check.at(s).at(j) = false;
        }
      }
    }
  }
  for(int i=0; i<grid.size(); i++){
    bool flag= false;
    for(int j=0; j<grid.at(i).size(); j++){
      if(check.at(i).at(j) == true){
        cout << grid.at(i).at(j);
        flag = true;
      }
    }
    if(flag){
      cout << endl;
    }
  }

return 0;
}
