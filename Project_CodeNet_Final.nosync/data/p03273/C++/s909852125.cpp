#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector <string> a(H);
  for(int i = 0; i < H; i++) {
    cin >> a[i];
  }

  vector <vector <bool>> b(H);
  for(int i = 0; i < H; i++) {
    vector <bool> tmp;
    for(int j = 0; j < W; j++) {
      tmp.push_back(true);
    }
    b[i] = tmp;
  }
  
  for(int i = 0; i < H; i++) {
    bool w = false;
    for(int j = 0; j < W; j++) {
      if(a[i][j] == '#') {
	w = true;
	break;
      }
    }
    if(!w) {
      for(int k = 0; k < W; k++) {
	b[i][k] = false;
      }
    }
  }

  for(int j = 0; j < W; j++) {
    bool w = false;
    for(int i = 0; i < H; i++) {
      if(a[i][j] == '#') {
	w = true;
	break;
      }
    }
    if(!w) {
      for(int k = 0; k < H; k++) {
	b[k][j] = false;
      }
    }
  }

  for(int i = 0; i < H; i++) {
    bool foo = false;
    for(int j = 0; j < W; j++) {
      if(b[i][j]) {
	cout << a[i][j];
	foo = true;
      }
    }
    if(foo) {
      cout << endl;
    }
  }
  
}