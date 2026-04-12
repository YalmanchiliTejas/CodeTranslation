#include <iostream>
#include <algorithm>

using namespace std;

char inputs[10][10];
char tmp[10][10];
char ans[10][10];
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {-1, 0, 1, 0, 0};

void through(int y, int x){
  ans[y][x] = '1';
  for(int i=0;i<5;i++){
    int ty = y + dy[i];
    int tx = x + dx[i];
    if(ty<0 || ty>=10) continue;
    if(tx<0 || tx>=10) continue;
    if(tmp[ty][tx] == '1')tmp[ty][tx] = '0';
    else tmp[ty][tx] = '1';
  }
}

bool check(){
  for(int i=1;i<10;i++){
    for(int j=0;j<10;j++){
      if(tmp[i-1][j] == '1') through(i, j);
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(tmp[i][j] == '1') return false;
    }
  }
  return true;
}

main(){
  int t;
  cin >> t;
  for(int tc=1;tc<=t;tc++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	cin >> inputs[i][j];
      }
    }
    for(int i=0;i<(1<<10);i++){
      fill(ans[0], ans[10], '0');
      for(int j=0;j<10;j++){
	for(int k=0;k<10;k++){
 	  tmp[j][k] = inputs[j][k];
	}
      }
      for(int j=0;j<10;j++){
	if(i & (1<<j)) through(0, j);
      }
      /*for(int j=0;j<10;j++){
	cout << ans[0][j];
	}cout << endl;*/
      if(check()) break;
    }
    for(int i=0;i<10;i++){
      cout << ans[i][0];
      for(int j=1;j<10;j++){
	cout << ' ' << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}