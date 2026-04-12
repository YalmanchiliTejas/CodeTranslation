#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++) 
#define rep(i,n); for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b); 
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
// int dx[]={0,1,0,-1,1,-1,-1,1};
// int dy[]={1,0,-1,0,1,1,-1,-1};
int dx[]={1,0};
int dy[]={0,1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/
char a[8][8];
bool re[8][8];
int h,w;

void dfs(int x,int y){
  re[x][y]=true;
  rep(i,2){
    if(x+dx[i]<0||h-1<x+dx[i]||y+dy[i]<0||w-1<y+dy[i]) continue;
    if(a[x+dx[i]][y+dy[i]]=='#'){
      dfs(x+dx[i],y+dy[i]);
      break;
    }
  }
}

signed main(){
  cin>>h>>w;
  string ans="Possible";
  rep(i,h){
    rep(j,w) cin>>a[i][j];
  }
  dfs(0,0);
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'&&!re[i][j]) ans="Impossible";
    }
  }

  cout<<ans<<endl;
  return 0;
}