#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int lH = H;
  int lW = W;
  vector<vector<char>> table(H, vector<char>(W));
  for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
          cin >> table[i][j];
      }
  }
  bool hasBlack = false;
  int i=0;
  int j=0;
  
  for(i=0;i<lH;i++){
      for(j=0;j<lW;j++)
        if(table[i][j] == '#') hasBlack = true;
    
      if(!hasBlack){
          lH -= 1;
          for(int p=i;p<lH;p++)
              for(int q=0;q<lW;q++)
                table[p][q] = table[p+1][q];
        i -= 1;
      }
      hasBlack = false;
  }
  
  for(i=0;i<lW;i++){
      for(j=0;j<lH;j++)
          if(table[j][i] == '#') hasBlack = true;

      if(!hasBlack){
          lW -= 1;
          for(int p=0;p<lH;p++)
              for(int q=i;q<lW;q++)
                table[p][q] = table[p][q+1];
        i -= 1;
      }
      hasBlack = false;
  }
  
    for(i=0;i<lH;i++){
      for(j=0;j<lW;j++)
          cout << table[i][j];
      cout << endl;
    }
}