#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  int x=0,y=0;
  bool f = true;
  char field[8][8];
  cin >> h >> w;
  for(int x=0;x<h;x++){
    for(int y=0;y<w;y++){
      cin >> field[x][y];
    }
  }
  if(field[x][y] == '#') field[x][y] = '.';
  else f = false;
  while(((x!=h-1)||(y!=w-1))&&f){
    if(x+1!=h && field[x+1][y] == '#'){
        field[++x][y] = '.';
    }else if(y+1!=w && field[x][y+1] == '#'){
        field[x][++y] = '.';
    }else f = false;
  }
  for(int x=0;x<h;x++){
    for(int y=0;y<w;y++){
      if(field[x][y] == '#') f = false;
    }
  }
  cout << (f?"Possible":"Impossible") << endl;
}