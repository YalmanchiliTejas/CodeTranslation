#include<iostream>
#include<queue>
#include<map>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const int N = 4;
const int inf = (1<<20);
bool edge[N][N][N][N];
int cost[(1<<16)];
char m[N][N+1];

int encode(bool in[4][4]){
  int ret=0;
  rep(i,4){
    rep(j,4){
      if (in[i][j])ret|=((1<<(j+i*4)));
    }
  }
  return ret;
}

void decode(bool in[4][4],int now){
  rep(i,4){
    rep(j,4){
      in[i][j]=now%2==1;
      now/=2;
    }
  }
}

int fill(int t,int b,int l,int r,bool st[4][4],char color){
  bool cpy[4][4];
  rep(i,4)rep(j,4)cpy[i][j]=st[i][j];
  for(int i=t;i<=b;i++){
    for(int j=l;j<=r;j++){
      if (color == m[i][j])cpy[i][j]=true;
      else cpy[i][j]=false;
    }
  }
  return encode(cpy);
}

string color="RGB";
int solve(){
  bool st[4][4];
  rep(i,(1<<16))cost[i]=inf;
  queue<int> Q;
  Q.push(0);
  cost[0]=0;
  while(!Q.empty()){
    int now=Q.front();Q.pop();
    if (now == (1<<16)-1)return cost[now];
    decode(st,now);
    rep(i,4){
      REP(ii,i,4){
	rep(j,4){
	  REP(jj,j,4){
	    if (!edge[i][ii][j][jj])continue;
	    rep(l,4){
	      int next=fill(i,ii,j,jj,st,color[l]);
	      if (cost[next] == inf){
		cost[next]=cost[now]+1;
		Q.push(next);
	      }
	    }
	  }
	}
      }
    }

  }
  return -1;
}

void makePattern(int h,int w){
  for(int i=-3;i < 4;i++){//top
    if (i+h <= 0)continue;
    for(int j=-3;j < 4;j++){//left
      if (j+w <= 0)continue;
      int l=max(0,j),r=min(3,j+w-1),t=max(0,i),b=min(3,i+h-1);
      edge[t][b][l][r]=true;
      /*
      cout << i <<" " << j <<" " << w <<" " << h <<" can push " << l <<" - " << t <<" : " << r <<" - "<< b << endl;
      rep(ii,4){
	rep(jj,4){
	  if (t <= ii && ii <= b && l <= jj && jj <= r)cout << "1";
	  else cout <<"0";
	}
	cout << endl;
      }
      cout << endl;
      */
    }
  }
}

main(){
  int n;
  while(cin>>n){
    rep(i,4)rep(j,4)rep(k,4)rep(l,4)edge[i][j][k][l]=false;
    rep(i,n){
      int w,h;
      cin>>w>>h;
      makePattern(w,h);
    }
    rep(i,4)cin>>m[i];
    cout << solve() << endl;
  }
  return 0;
}