#include <iostream>
#include <vector>

using namespace std;

int main(){
 
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> data(h, vector<char>(w));
  
  for(int i = 0; i < h; i++){
    bool f_white = true;
    for(int j = 0; j < w; j++){
      cin >> data[i][j];
      if(data[i][j] == '#'){
        f_white = false;
      }
    }
    if(f_white){
      for(int j = 0; j < w; j++){
        data[i][j] = 'x';
      }
    }
  }
  
  for(int j = 0; j < w; j++){
    bool f_white = true;
    for(int i = 0; i < h; i++){
      if(data[i][j] == '#'){
        f_white = false;
      }
    }
    if(f_white){
      for(int i = 0; i < h; i++){
        data[i][j] = 'x';
      }
    }
  }
  
  for(int i = 0; i < h; i++){
    bool f_nout = true;
    for(int j = 0; j < w; j++){
      if(data[i][j] != 'x'){
        cout << data[i][j];
        f_nout = false;
      }
    }
    if(!f_nout){
      cout << endl;
    }
  }
  
  return 0;
}