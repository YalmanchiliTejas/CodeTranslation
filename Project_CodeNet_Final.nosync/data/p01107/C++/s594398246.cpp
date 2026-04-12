#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool in(int y,int x){
  return 0<=y&&y<n&&0<=x&&x<m;
}
signed main(){
  while(cin>>n>>m,n||m){
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    int cnt[4][n][m];
    memset(cnt,0,sizeof(cnt));
    int ng=0;
    //AD
    //BC
    int sy[]={0,n-1,n-1,0};
    int sx[]={0,0,m-1,m-1};
    for(int i=0;i<4;i++){
      int y=sy[i],x=sx[i],dir=(i+2)%2;
      int gy=sy[(i+1)%4],gx=sx[(i+1)%4];
      int used[4][n][m];
      int ay[]={-1,0,1,0};
      int ax[]={0,-1,0,1};
      memset(used,0,sizeof(used));
      while(y!=gy||x!=gx){
	cnt[i][y][x]=1;
	if(used[dir][y][x]) break;
	used[dir][y][x]=1;
	//cout<<y<<" "<<x<<" "<<dir<<endl;
	int ny=y+ay[dir],nx=x+ax[dir];
	if(in(ny,nx)&&s[ny][nx]=='.'){
	  y=ny;x=nx;
	  ny=y+ay[(dir+3)%4];nx=x+ax[(dir+3)%4];
	  if(in(ny,nx)&&s[ny][nx]=='.'){
	    cnt[i][y][x]=1;
	    y=ny;x=nx;dir=(dir+3)%4;
	  }
	}else{
	  dir=(dir+1)%4;
	}
      }
      if(y!=gy||x!=gx){
	cout<<"NO"<<endl;
	ng=1;
	break;
      }
    }
    if(ng) continue;
    /*
    for(int k=0;k<4;k++){
      for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	  cout<<cnt[k][i][j];
	}
	cout<<endl;
      }
      cout<<endl;
    }
    */
    bool flg=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	int tmp=0;
	for(int k=0;k<4;k++){
	  if(cnt[k][i][j]) tmp++;
	}
	if(tmp>1){
	  cout<<"NO"<<endl;
	  flg=0;
	}
	if(!flg) break;
      }
      if(!flg) break;
    }
    if(flg) cout<<"YES"<<endl;
  }
  return 0;
}