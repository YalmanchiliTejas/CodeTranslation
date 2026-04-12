#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, i, j;
  cin >> H >> W;
  
  vector<vector<char>> a(H,vector<char>(W));
  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }



  for(j = 0; j < W; j++){
    bool tate = true;
    
    for(i = 0; i < H; i++){
      if(a.at(i).at(j) == '#'){
	tate = false;
	break;
      }
    }

    if(tate){
      for(i = 0; i < H; i++)
	a.at(i).at(j) = '|';
    }
  }
  
  for(i = 0; i < H; i++){
    bool yoko = true;
    
    for(j = 0; j < W; j++){
      if(a.at(i).at(j) == '#'){
	yoko = false;
	break;
      }
    }
    
    if(yoko){
      for(j = 0; j < W; j++)
	a.at(i).at(j) = '-';
    }
  }
  
  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      if(a.at(i).at(j) == '-'){
	continue;
      }
      if(a.at(i).at(j) == '|'){
	if(j == W-1){
	  cout << endl;
	}
	continue;
      }
      cout << a.at(i).at(j);

      if(j == W-1)
	cout << endl;
    }
  }
}
