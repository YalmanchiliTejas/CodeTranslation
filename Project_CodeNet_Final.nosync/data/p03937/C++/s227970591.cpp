#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  string b[8];
  cin >> H >> W;
  for(int i=0; i<H; i++){
    cin >> b[i];
  }
  int posx=0, posy=0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(b[i][j]=='#'){
        if(i<posx || j<posy){
          cout << "Impossible" << endl;
          return 0;
        }else{
          posx = i;
          posy = j;
        }
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}