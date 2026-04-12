#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, i, j, k;
  cin >> H >> W;
  vector<vector<char>> g(H, vector<char>(W));
  
  for(i=0; i<H; i++)
    for(j=0; j<W; j++)
      cin >> g.at(i).at(j);
  
  for(i=0; i<H; i++) {
    for(j=0; j<W; j++) {
      if(j == 0) {
        for(k=0; k<W; k++)
          if(g.at(i).at(k) != '.')
            break;
        if(k == W)
          break;
      }
      if(g.at(i).at(j) == '.') {
        for(k=0; k<H; k++)
          if(g.at(k).at(j) != '.')
            break;
        if(k == H)
          continue;
      }
      cout << g.at(i).at(j);
    }
    if(j != 0)
      cout << endl;
  } 
}