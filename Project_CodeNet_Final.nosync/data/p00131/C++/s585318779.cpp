#include <bits/stdc++.h>
using namespace std;


void mark(int mp[10][10],int y,int x){
  int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
  for(int i=0;i<4;i++) {
    int nx=x+dx[i],ny=y+dy[i];
    if(nx<0||ny<0||nx>=10||ny>=10)continue;
    mp[ny][nx]=!mp[ny][nx];
  }
  mp[y][x]=!mp[y][x];
}

bool check(int mp[10][10]){
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)if(mp[i][j])return 0;
  return 1;
}

int main(){
  int q;
  cin>>q;
  while(q--){
    int mp[10][10],b[10][10];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>mp[i][j],b[i][j]=mp[i][j];

    int ans[10][10]={};
    for(int i=0;!check(mp);i++){
      for(int j=0;j<10;j++)for(int k=0;k<10;k++) mp[j][k]=b[j][k];
      for(int j=0;j<10;j++)for(int k=0;k<10;k++) b[j][k]=mp[j][k];

      for(int j=0;j<10;j++)if((ans[0][j]=((i>>j)%2)))mark(mp,0,j);
      for(int j=1;j<10;j++)
	for(int k=0;k<10;k++)
	  if((ans[j][k]=mp[j-1][k]))mark(mp,j,k);
    }

    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	if(j) cout <<" ";
	cout << ans[i][j];
	assert(ans[i][j]==0||ans[i][j]==1);
      }
      cout <<endl;
    }
  }
  return 0;
}