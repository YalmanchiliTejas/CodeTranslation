#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> table(h, vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> table[i][j];
    }
  }
  vector<bool> row(h, false);
  vector<bool> col(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (table[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
  for(int i=0;i<h;i++){
    if(row[i]){
      for(int j=0;j<w;j++){
        if(col[j]){
          cout << table[i][j];
        }
      }
      cout << endl;
    }
  }
}