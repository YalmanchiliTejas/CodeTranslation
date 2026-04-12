#include <iostream>

using namespace std;

int main(void){
  int H, W;
  cin >> H >> W;
  
  int i, j;
  char a[H][W];
  for(i=0; i<H; i++)
    for(j=0; j<W; j++)
      cin >> a[i][j];

  //行方向に.(白文字)を見て，全てが.であれば，空白に置き換える
  for(i=0; i<H; i++){
    for(j=0; j<W; j++)
      if(a[i][j] == '#')
	break;
    if(j >= W)
      for(j=0; j<W; j++)
	a[i][j] = ' ';
  }

  //列方向に.(白文字)を見て，全てが.であれば，空白に置き換える
  for(i=0; i<W; i++){
    for(j=0; j<H; j++)
      if(a[j][i] == '#')
	break;
    if(j >= H){
      for(j=0; j<H; j++)
        a[j][i] = ' ';
    }
  }
  

  int count = 0;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(a[i][j] != ' '){
	cout << a[i][j];
	count ++;
      }
    }
      if(count != 0)
	cout << endl;
    count = 0;
  }
      
  return 0;
}
