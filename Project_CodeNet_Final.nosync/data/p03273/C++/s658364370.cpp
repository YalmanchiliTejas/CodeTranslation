#include <iostream>
using namespace std;

#define SZ 100

int rowSum[SZ], fileSum[SZ];
  
int main(void){
  char fld[SZ][SZ];
  int w,h;
  
  cin >> h >> w;
  for (int i=0; i<h; i++){
    char buf[SZ];
    cin >> buf;
    for (int j=0; j<w; j++){
      fld[j][i] = buf[j];
      rowSum[i] += fld[j][i]=='#'?1:0;
      fileSum[j] += fld[j][i]=='#'?1:0;
    }
  }
  for (int i=0; i<h; i++){
    int flg=0;
    for (int j=0; j<w; j++){
      if (fileSum[j] && rowSum[i]){
        cout << fld[j][i];
        flg = 1;
      }
    }
    if (flg) cout << endl;
  }
}