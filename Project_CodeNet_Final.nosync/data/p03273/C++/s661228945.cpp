#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, W; cin >> H >> W; char table[H][W];
  
  vector<int> vecH, vecW;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table[i][j];
    }
  }
  
  for (int i = 0; i < H; i++) {
    int tmp = 0;
    for (int j = 0; j < W; j++) {
      if (table[i][j] == '.') tmp++;
    }
    if (tmp == W) vecH.push_back(i);
  }
  
  for (int i = 0; i < W; i++) {
    int tmp = 0;
    for (int j = 0; j < H; j++) {
      if (table[j][i] == '.') tmp++;
    }
    if (tmp == H) vecW.push_back(i);
  }
  
  for (int i = 0; i < H; i++) {
    
    bool lineFlag = true; bool Hflag = true;
    
    for (int x : vecH) {
      if (x == i) {
        Hflag = false;
        lineFlag = false;
      }
    }
    
    if (Hflag) {
    
      for (int j = 0; j < W; j++) {
        
        bool Wflag = true;
        
        for (int y : vecW) {
          if (y == j) Wflag = false;
        }
        
        if (Wflag) cout << table[i][j];
        
      }
      
    }
    
    if (lineFlag) cout << endl;
    
  }
  
}