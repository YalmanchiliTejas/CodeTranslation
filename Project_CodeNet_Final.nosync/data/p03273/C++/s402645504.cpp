#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  // (ここで2次元配列を宣言)
  vector<vector<char>> Table(H,vector<char>(W));
  
  for (int i= 0; i<H; i++){
    for(int j= 0; j<W; j++) {
	  cin >> Table.at(i).at(j);
	}
  }
  
  // compress
  vector<bool> row(H, false);
  vector<bool> col(H, false);
  for (int i= 0; i<H; i++){
    for(int j= 0; j<W; j++) {
	  if (Table.at(i).at(j) =='#') {
		row[i] = true;
		col[j] = true;
	  }
    }
  }
  
	cerr << ' ';
	for (int i = 0; i < H; i++) 	cerr << col[i];
	cerr << endl;
	for (int i = 0; i < H; i++) 	cerr << row[i] << endl;
	
	
  for (int i=0; i<H; i++) {
  	if (row[i] == true) {
	  	for (int j=0; j<W; j++) {
		  	if (col[j] == true) {
				cout << Table.at(i).at(j);
			}
	  	}
	cout << endl;
  	}
  }
}

