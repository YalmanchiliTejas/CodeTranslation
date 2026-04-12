#include <iostream>
using namespace std;

int main(void){
  int H,W;
  cin >> H >> W;
  char a[H][W]={};
  int h[H]={},w[W]={};
  for(int i=0;i<H;i++){
    cin >> a[i];
    for(int j=0;j<W;j++){
      h[i]+=(a[i][j]=='#');
    }
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      w[j]+=(a[i][j]=='#');
    }
  }
  int c=0;
  for(int i=0;i<H;i++){
    if(h[i]==0){
      c++;
      continue;
    }
    for(int j=0;j<W;j++){
      if(w[j]==0){
        continue;
      }
      cout << a[i][j];
    }
    cout << endl;
  }
  if(c==H)
    cout <<endl;
  return 0;
}
