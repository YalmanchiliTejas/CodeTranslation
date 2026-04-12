#include <iostream>
#include <cstdio>
#define rep(i,n) for(int i = 0 ; i < n ; i++ )
#define cc(a,n) 0<=(a) && (a) < n
#define INF 1000000
using namespace std;
int n;
int ma[16][16] = {{0}};
int dfs(int px,int py,int cnt){
  ma[px][py] = cnt;
  if(cnt == n*n)return 0; 
  int nx = px+1,ny = py+1;

  while(1){
    if(n <= nx){
      nx = 0;
    }else if(0 > nx){
      nx = n-1;
    }else if(n <= ny){
      ny = 0;
    }else if(ma[nx][ny] != 0){
      nx--;
      ny++;
    }
    if(ma[nx][ny] == 0&&cc(nx,n)&&cc(ny,n))break;
  }
  dfs(nx,ny,cnt+1);
}
int main(){

  while(cin >> n,n){
    rep(i,n+1)rep(j,n+1)ma[i][j] = INF;
    rep(i,n)rep(j,n)ma[i][j] = 0;

    int px = n/2,py = (n/2)+1;
    int t = dfs(px,py,1);
    rep(i,n){
      rep(j,n){
	printf("%4d",ma[j][i]);
      }
      cout << endl;
    }
  }

  return 0;
}