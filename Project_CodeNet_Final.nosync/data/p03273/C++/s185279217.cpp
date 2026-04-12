#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> M(H);

  int h_ = 0;
  int flag = 1;
  int n = 0;
  
  for(int h=0; h<H; h++) {
    cin >> M[h_];
    
    for(int w=0; w<W; w++) {
      if(M[h_][w] == '.') {
        flag = 1;
      } else {
        flag = 0;
        h_++;
        break;
      }
    }
    if(flag == 1) {
      n++;
    }
  }
  
  flag = 1;
  int w_ = 0;
  
  for(int w=0; w<W; w++) {
    for(int h=0; h<H-n; h++) {
      if(M[h][w_] == '.') {
        flag = 1;
      } else {
        flag = 0;
        w_++;
        break;
      }
    }
    if(flag == 1) {
      for(int h=0; h<H-n; h++) {
        M[h].erase(w_,1);
      }
    }
  }
    
  for(int h=0; h<M.size()-n; h++) {
    cout << M[h] << endl;
  }
  
  return 0;
}