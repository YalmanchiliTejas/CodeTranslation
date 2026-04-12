#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[10][10],b[10][10],c[10][10],TEST;
int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};
bool solve(int x){
  r(i,10)if((x>>i)&1){
    c[0][i]=1;
    r(j,5){
      int y=dy[j];
      int x=dx[j]+i;
      if(y<0||x<0||y>9||x>9)continue;
      b[y][x]=(b[y][x]+1)%2;
    }
  }
  for(int i=0;i<9;i++){
    r(j,10){
      if(b[i][j]){
        c[i+1][j]=1;
        r(k,5){
          int y=i+dy[k]+1;
          int x=j+dx[k];
          if(y<0||x<0||y>9||x>9)continue;
          b[y][x]=(b[y][x]+1)%2;
        }
      }
    }
  }
  r(i,10)r(j,10)if(b[i][j])return 0;
  return 1;
}
int main(){
  cin>>TEST;
  while(TEST--){
    r(i,10)r(j,10)cin>>a[i][j];
    for(int i=0;i<(1<<10);i++){
      r(k,10)r(j,10)b[k][j]=a[k][j];
      memset(c,0,sizeof(c));
      if(solve(i)){
        r(i,10){
          r(j,10){
            if(j)cout<<' ';
            cout<<c[i][j];
          }
          cout<<endl;
        }
        goto L;
      }
    }L:;
  }
}