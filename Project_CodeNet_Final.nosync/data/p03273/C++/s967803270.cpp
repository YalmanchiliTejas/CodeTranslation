#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H,vector<char>(W,'-'));
  for(int i = 0;i < H; i++){
  	for(int j = 0; j< W; j++){
    	cin >> map.at(i).at(j);
    }
  }
  for(int i = 0;i < H; i++){
    int flag = 1;
  	for(int j = 0; j< W; j++){
    	if(map.at(i).at(j) == '#'){
        	flag = 0;
          	break;
        }
    }
    if(flag){
    	map.erase(map.begin() + i);
      	i--;
      	H--;
    }
  }
  for(int j = 0; j< W; j++){
    int flag = 1;
  	for(int i = 0;i < H; i++){
    	if(map.at(i).at(j) == '#'){
        	flag = 0;
          	break;
        }
    }
    if(flag){
     	for(int i = 0;i < H; i++){
      		map.at(i).erase(map.at(i).begin() + j);
      	}
   	  	j--;
      	W--;
    }
  }
  for(int i = 0; i< H; i++){
  	for(int j = 0; j < W; j++){
    	cout << map.at(i).at(j);
    }
    cout << endl;
  }
}
