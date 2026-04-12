#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  bool sp;
  
  cin >> H >> W;
  
  vector<vector<char>> pace(H,vector<char>(W));
  for(int i = 0; i < H;i++){
  	for(int j = 0; j < W;j++){
    	cin >> pace.at(i).at(j);
    }
  }
 
  for(int i = 0; i < W;i++){
    sp = true;
  	for(int j = 0; j < H;j++){
      if(pace.at(j).at(i) == '#'){
        sp = false;
      	break;
      }
    }
    if(sp){
    	for(int j = 0; j < H;j++){
        	pace.at(j).at(i) = '_';
        }
    }
  }
  for(int i = 0; i < H;i++){
    sp = true;
  	for(int j = 0; j < W;j++){
    	if(pace.at(i).at(j) == '#'){
        sp = false;
      	break;
      }
    }
    if(sp){
        pace.at(i).at(0) = 'd';     
    }
  }
  
  for(int i = 0; i < H;i++){
    sp = true;
  	for(int j = 0; j < W;j++){
      if(pace.at(i).at(0) == 'd'){
        sp = false;
      	break;
      }
      if(pace.at(i).at(j) != '_')
      cout << pace.at(i).at(j);
    }
    if(sp){
    	cout << endl;
    }
  }

}
