#include<bits/stdc++.h>
using namespace std;

int main() {
	int H,W;
  	cin >> H >> W;
  
  	vector<vector<char>> vec(H,vector<char>(W));
  
  	for(int i = 0; i < H; i++) {
    	for(int j = 0; j < W; j++) {
        	cin >> vec.at(i).at(j);
        }
    }
  
  	vector<int> hor(H,0);
  	vector<int>	ver(W,0);
  
  	for(int i = 0; i < H; i++) {
      bool can = true;
    	for(int j = 0; j < W; j++) {
        	if(vec.at(i).at(j) == '#') {
            	can = false;
            }
        }
          if(can) hor.at(i)++;
    }
  
  	  
  	for(int i = 0; i < W; i++) {
      bool can = true;
    	for(int j = 0; j < H; j++) {
        	if(vec.at(j).at(i) == '#') {
            	can = false;
            }
        }
          if(can) ver.at(i)++;
    }
  	
  	for(int i = 0; i < H; i++) {
      if(hor.at(i) == 0) {
    	for(int j = 0; j < W; j++) {
        	if(ver.at(j) == 0) {
            cout << vec.at(i).at(j);
            }
        }
        cout << endl;
      }
    }
  	
 }