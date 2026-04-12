#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,m,o,r,c,size,angle;
int a[20][20],b[20][20];
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};

void rot(int y1, int x1, int y2, int x2){
  for(int i=0;i<y2-y1;i++){
    for(int j=0;j<x2-x1;j++){
      b[j][i] = a[y2-1-i][x1+j];
    }
  }

  for(int i=0;i<y2-y1;i++){
    for(int j=0;j<x2-x1;j++){
      a[y1+i][x1+j] = b[i][j];
    }
  }
}

void dfs(int y,int x,int col){
  if(a[y][x] != col)return;
  a[y][x] = 1-col;

  rep(i,4){
    int ny = y+dy[i], nx = x+dx[i];
    if(ny<0 || nx<0 || ny>=n || nx>=n)continue;
    dfs(ny,nx,col);
  }
}

int main(){
  cin >> n >> m;
  rep(i,n)rep(j,n)cin >> a[i][j];

  rep(i,m){
    cin >> o;
    if(o == 0){
      cin >> r >> c >> size >> angle; r--; c--;
      rep(i,angle/90)rot(r,c,r+size,c+size);
    }
    if(o == 1){
      cin >> r >> c >> size; r--; c--;
      rep(i,size){
	rep(j,size){
	  a[r+i][c+j] = 1-a[r+i][c+j];
	}
      }
    }
    if(o == 2){
      cin >> r; r--;
      int tmp = a[r][0];
      rep(i,n-1){
	a[r][i] = a[r][i+1];
      }
      a[r][n-1] = tmp;
    }
    if(o == 3){
      cin >> r; r--;
      int tmp = a[r][n-1];
      rep(i,n-1){
	a[r][n-1-i] = a[r][n-2-i];
      }
      a[r][0] = tmp;
    }
    if(o == 4){
      cin >> r >> c; r--; c--;
      dfs(r,c,a[r][c]);
    }
  }
  rep(i,n){
    rep(j,n)cout << a[i][j] << ((j==n-1)?"\n":" ");
  }
}
  