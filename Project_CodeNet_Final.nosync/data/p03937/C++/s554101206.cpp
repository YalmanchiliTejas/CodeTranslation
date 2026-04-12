#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  string S[H];
  int cnt=0;
  for (int i=0;i<H;i++){
    cin >> S[i];
    for (int j=0;j<W;j++){
      if (S[i][j]=='#') cnt++;
    }
  }
  if (cnt!=H+W-1){
    cout << "Impossible" << endl;
    return 0;
  }
  int x=0;
  int y=0;
  while (S[y][x]=='#'){
    if(x!=W-1){
      if (S[y][x+1]=='#') x++;
      else y++;
    }
    else y++;
    if (y==H){
      cout << "Possible" << endl;
      return 0;
    }
  }
    if (x==H-1 and y==W-1){
      cout << "Possible" << endl;
      return 0;
    }
    else{
      cout << "Impossible" << endl;
      return 0;
    }
}