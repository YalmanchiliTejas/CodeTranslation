#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  vector<bool> tate(H, false) ;
  vector<bool> yoko(W, false) ;
  
   for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    cin >> data.at(i).at(j) ;
    }
   }
  
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (data.at(i).at(j) == '#') {
				tate.at(i) = true;
				yoko.at(j) = true;
			}
		}
	}

for (int i = 0; i < H; i++) {	
   if (tate.at(i)){
	 for (int j = 0; j < W; j++) {
		if ( yoko.at(j)) {
			cout << data.at(i).at(j);
		}
	 }
     cout << endl;
   }					
}
  
}
  
