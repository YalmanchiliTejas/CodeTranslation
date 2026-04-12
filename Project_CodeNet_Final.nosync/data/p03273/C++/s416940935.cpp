#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char A[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
    }
  }
  for(int i=0;i<H;i++){
    bool ans = true;
    for(int j=0;j<W;j++){
      if(A[i][j] == '#') ans = false;
    }
    if(ans){
      for(int j=0;j<W;j++){
        A[i][j] = '1';
      }
    }
  }

  for(int i=0;i<W;i++){
    bool ans = true;
    for(int j=0;j<H;j++){
      if(A[j][i] == '#') ans = false;
    }
    if(ans){
      for(int j=0;j<H;j++){
        A[j][i] = '1';
      }
    }
  }
  for(int i=0;i<H;i++){
    bool ans1 = false;
    for(int j=0;j<W;j++){
      if(A[i][j] == '.' || A[i][j] == '#'){
        cout << A[i][j];
        ans1 = true;
      }
    }
    if(ans1) cout << endl;
  }
}