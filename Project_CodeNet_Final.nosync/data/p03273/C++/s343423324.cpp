#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; //縦、横
  cin >> H >> W;
  string data[H];
  for (int i = 0; i < H; i++) {
    cin >> data[i];
  }
  bool Hline[H], Wline[W];
  for (int i = 0; i < H; i++) Hline[i] = false;
  for (int i = 0; i < W; i++) Wline[i] = false;
  for (int i = 0; i < H; i++) {
  	for (int j = 0; j < W; j++) {
        if (data[i][j] == '#') {
        	Hline[i] = true;
          	Wline[j] = true;
        }
    }
  }
  
  for (int i = 0; i < H; i++) {
    int count = 0;
  	for (int j = 0; j < W; j++) {
        if (!Hline[i] || !Wline[j]) {
			count += 1;
        } else {
        	cout << data[i][j];
        }
    }
    if (count != W) cout << endl;
  }
}
