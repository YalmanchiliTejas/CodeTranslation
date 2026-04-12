#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
  	for (int j = 0; j < W; j++){
    	cin >> data.at(i).at(j);
    }
  }
  
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < W; j++){
    	if (data.at(i).at(j) == '#') {
        	break;
        }
      	else if (j == W - 1) {
          data.erase(data.begin() + i);
          i--;
        }
    }
  }
  
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < data.size(); i++){
    	if (data.at(i).at(j) == '#') {
        	break;
        }
      	else if (i == data.size() - 1) {
        	for (int k = 0; k < data.size(); k++) {
            	data.at(k).at(j) = 'X';
            }
        }
    }
  }
  
  for (int i = 0; i < data.size(); i++) {
  	for (int j = 0; j < W; j++){
      	if (data.at(i).at(j) == 'X'){
        	continue;
        }
    	cout << data.at(i).at(j);
    }
    cout << endl;
  }
  
}


