#include<bits/stdc++.h>
using namespace std;

int x, y;
string board[110];
bool goodx[110], goody[110];

int main(){
  cin >> x >> y;
  for(int i = 0; i < x; i++){
    cin >> board[i];
  }
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      if(board[i][j] == '#'){
        goodx[i] = true;
        goody[j] = true;
      } 
    }
  }
  for(int i = 0; i < x; i++){
    if(goodx[i]){
      for(int j = 0; j < y; j++){
        if(goody[j]){
          cout << board[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}