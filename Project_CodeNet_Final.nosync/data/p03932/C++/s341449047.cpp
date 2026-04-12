#include <bits/stdc++.h>
using namespace std;
bool check(int n,int m,int x,int y) {return x>=0&&x<n&&y>=0&&y<m;}

int dp[401][401][401],dx[2]={0,1},dy[2]={1,0};
int main() {
  int n,m;
  cin >> n >> m;
  int a[n][m];
  for(int i=0; i<n; i++)for(int j=0; j<m; j++) cin >> a[i][j];
  for(int i=0;i<401;i++)for(int j=0;j<401;j++)for(int k=0;k<401;k++)dp[i][j][k]=-(1<<29);
  dp[0][0][0]=a[0][0];
  for(int i=0; i<n+m-2; i++) {
    for(int j=0; j<n+m; j++) {
      int x1,y1,x2,y2;
      if(i<m) x1=0,y1=i;
      else x1=i-m+1,y1=m-1;
      x1+=j,y1-=j;
      if(!check(n,m,x1,y1)) break;
      for(int k=j; k<n+m; k++) {
        if(i<m) x2=0,y2=i;
        else x2=i-m+1,y2=m-1;
        x2+=k,y2-=k;
        if(!check(n,m,x2,y2)) break;
        if(dp[i][j][k]==-(1<<29)) continue;
        for(int l=0; l<2; l++) {
          int xx1=x1+dx[l],yy1=y1+dy[l];
          if(!check(n,m,xx1,yy1)) continue;
          for(int l2=0; l2<2; l2++) {
            int xx2=x2+dx[l2],yy2=y2+dy[l2];
            if(!check(n,m,xx2,yy2)) continue;
            int c=a[xx1][yy1]+a[xx2][yy2];
            if(xx1==xx2&&yy1==yy2) c/=2;
            int x=xx1,y=xx2;
            if(i+1>=m) x-=i-m+2,y-=i-m+2;
            dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]+c);
          }
        }
      }
    } 
  }
  cout << dp[n+m-2][0][0] << endl;
  return 0;
}
