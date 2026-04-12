#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>>grid;
  vector<bool> delete_line_flag(120, true);
  vector<bool> delete_col_flag(120, true);

  for(int i = 0; i < h; i++){
    vector<char>temp_grid(w);
    for(int j = 0; j < w; j++){
      cin >> temp_grid[j];
      if(temp_grid[j] == '#'){
        delete_line_flag[i] = false;
        delete_col_flag[j] = false;
      }
    }
    grid.push_back(temp_grid);
  }

  for(int i = 0; i < h; i++){
    if(delete_line_flag[i] == false){
      for(int j = 0; j < w; j++){
        if(delete_col_flag[j] == false){
          cout << grid[i][j];
        }
      }
      cout << endl;
    }
  }

}
