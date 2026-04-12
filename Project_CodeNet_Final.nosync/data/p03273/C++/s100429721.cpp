#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>>a(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(a.at(i).at(j) == '.'){
 
      bool isWhiteRow = true;
      for(int tj=0; tj<W; tj++){
        if(a.at(i).at(tj) == '#'){
          isWhiteRow = false;
          break;
        }
      }
      if(isWhiteRow){
        for(int tj=0; tj<W; tj++){
        a.at(i).at(tj) = '\0';
        }
      }

      bool isWhiteColumn = true;
      for(int ti=0; ti<H; ti++){
        if(a.at(ti).at(j) == '#'){
          isWhiteColumn = false;
          break;  
        }
      }
 
      if(isWhiteColumn){
        for(int ti=0; ti<H; ti++){
          a.at(ti).at(j)='\0';  
        }
      }
    }
    }
  }
    for(int i = 0; i < H; i++){
    int charNum = 0;
    for(int j = 0; j < W; j++){
      char out = a.at(i).at(j);
      if(out != '\0'){
        charNum++;
        cout << a.at(i).at(j);
      }
    }
    if(charNum != 0){
      cout << endl;
    }
  }
  return 0;

}
    