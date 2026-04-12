#include<iostream>
using namespace std;

bool grid[10][10];
int dy[] = {1,0,-1,0,0}, dx[] = {0,1,0,-1,0};

void rev(int y,int x){
  for(int i=0;i<5;i++){
    int sy = y+dy[i], sx = x+dx[i];
    if(sy<0 || sx<0 || sy>=10 || sx>=10)continue;
    grid[sy][sx] = !grid[sy][sx];
  }
}

int main(){
  int t;
  bool tmp[10][10];
  int ans[10][10];

  cin >> t;
  while(t--){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++)cin >> tmp[i][j];
    }
    
    for(int i=0;i<(1<<10);i++){
      for(int j=0;j<10;j++){
	for(int k=0;k<10;k++)grid[j][k] = tmp[j][k];
      }

      for(int j=0;j<10;j++){
	if(i&(1<<j)){
	  rev(0,j);
	  ans[0][j] = 1;
	}else ans[0][j] = 0;
      }

      for(int j=1;j<10;j++){
	for(int k=0;k<10;k++){
	  if(grid[j-1][k]){
	    rev(j,k);
	    ans[j][k] = 1;
	  }else ans[j][k] = 0;
	}
      }

      bool f = false;
      for(int j=0;j<10;j++)f |= grid[9][j];
      if(!f)break;
    }

    for(int i=0;i<10;i++){
      for(int j=0;j<9;j++)cout << ans[i][j] << " ";
      cout << ans[i][9] << endl;
    }
  }
}