#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  vector<bool> Hi(H, false);
  vector<bool> Wi(W, false);

  
  for(int i = 0; i < H; i++){
  	for(int j = 0; j < W; j++){
    	cin >> data[i][j];
    }
  }
  
  for(int i = 0; i < H; i++){
  	for(int j = 0; j < W; j++){
    	if(data[i][j] == '#'){
        	Hi[i] = true;
          	Wi[j] = true;
        }
    }
  }
  for(int i = 0; i < H; i++){
    if(Hi[i]){
   	  for(int j = 0; j < W; j++){
    	if(Wi[j]){
        	cout << data[i][j];
        }
      }
      cout << endl;
    }
  }
}