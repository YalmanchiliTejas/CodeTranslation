#include <bits/stdc++.h>
using namespace std;
int main(void){
  int H, W;
  cin >> H >> W;
  string S[H];
  for(int i=0; i<H; i++) cin >> S[i];

  int h = H;
  int w = W;
  
  bool tf_1 = true;
  bool tf_2 = true;
  while(tf_1 || tf_2){
    // 行の比較
    string comp_1 = "";
    for(int i=0; i<w; i++) comp_1 += ".";  
    for(int i=0; i<h; i++){
      string now_row = "";
      for(int j=0; j<w; j++) now_row += S[i][j];    
      if(now_row == comp_1){
        for(int j=i; j < h -1; j++){
          swap(S[j], S[j+1]);
        }
        h--;
        tf_1 = true;
        break;
      }
      tf_1 = false;
    }
    // 列の比較
    string comp_2 = "";
    for(int i=0; i<h; i++) comp_2 += ".";  
    for(int i=0; i<w; i++){
      string now_col = "";
      for(int j=0; j<h; j++) now_col += S[j][i];
      if(now_col == comp_2){
        for(int l=0; l < h; l++) {
          for(int k=i; k < w -1; k++){
            swap(S[l][k], S[l][k+1]);
          }
        }
        w--;
        tf_2 = true;
        break;
      }
      tf_2 = false;
    }    
  }
  
  // 結果の表示
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << S[i][j];
    }
    cout << endl;
  }
  return 0;
}