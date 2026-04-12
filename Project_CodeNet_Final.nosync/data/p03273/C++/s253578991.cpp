#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0 ; j < W ; j++){
    cin >> table.at(i).at(j);
    }
  }
	vector<bool> a(H,false);
  	vector<bool> b(W,false);
  
  for(int i=0; i<H ; i++){
    for(int j=0; j<W; j++){
      if(table.at(i).at(j)=='#'){
      	a.at(i) = true;
        b.at(j) = true;
      }
    }
  }
  
  for(int i=0; i<H; i++){
    if(a.at(i)){
   	for(int j=0; j<W; j++){ 
     		if(b.at(j)){
             	cout << table.at(i).at(j); 
            }
   		}
      cout << endl;
    }
  }

}