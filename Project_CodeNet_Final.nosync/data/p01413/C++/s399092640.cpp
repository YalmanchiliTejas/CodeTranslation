#include<iostream>
#include<map>
#include<cassert>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
typedef long long ll;
const int N =7;
const int inf = (1<<29);
int dp1[1<<N];

void precomp1(int n,int *x,int *y){
  int dp[1<<N][N];
  rep(i,(1<<n))rep(j,n)dp[i][j]=inf;
  rep(i,n){
    dp[(1<<i)][i]=abs(x[i])+abs(y[i]);
  }
  rep(i,(1<<n)){
    rep(j,n){//cur
      if (((1<<j)&i) == 0)continue;
      rep(k,n){//next
	if (((1<<k)&i) != 0)continue;
	int next=(1<<k)|i;
	dp[next][k]=min(dp[next][k],dp[i][j]+abs(x[j]-x[k])+abs(y[j]-y[k]));
      }      
    }
  }
  REP(i,1,(1<<n)){
    dp1[i]=inf;
    rep(j,n){
      dp[i][j]+=abs(x[j])+abs(y[j]);
      dp1[i]=min(dp1[i],dp[i][j]);
    }
  }
}

ll dp2[1<<N];
void precomp2(int m,int w,int bit,int *tv,int *weight){
  static ll dp[7][10000+1];
  rep(i,m)rep(j,w+1)dp[i][j]=0;
  rep(i,m){
    rep(j,w+1){
      if (j-weight[i] >= 0)dp[i][j]=dp[i][j-weight[i]]+tv[i];
      if (i)dp[i][j]=max(dp[i][j],dp[i-1][j]);
    }
  }
  dp2[bit]=0;
  rep(i,w+1)dp2[bit]=max(dp2[bit],dp[m-1][i]);
}

ll dp3[1<<N][10001];
ll solve(int n,int t){
  rep(i,(1<<n))rep(j,t+1)dp3[i][j]=0;
  rep(i,(1<<n)){
    rep(j,t+1){
      if (j-dp1[i] >= 0)dp3[i][j]=max(dp3[i][j],dp3[i][j-dp1[i]]+dp2[i]);
      if (i)dp3[i][j]=max(dp3[i][j],dp3[i-1][j]);
    }
  }
  ll ret=0;
  rep(i,t+1)ret=max(ret,dp3[(1<<n)-1][i]);
  return ret;
}

main(){
  int n,m,w,t;
  while(cin>>n>>m>>w>>t){
    map<string,int> M;
    int x[n],y[n],weight[m],value[m];
    rep(i,m){
      string tmp;
      cin>>tmp>>weight[i]>>value[i];
      M[tmp]=i;
    }
    int price[n][m];
    rep(i,n)rep(j,m)price[i][j]=0;
    rep(i,n){
      int l;
      cin>>l>>x[i]>>y[i];
      string tmp;
      rep(j,l){
	int g;
	cin>>tmp>>g;
	price[i][M[tmp]]=value[M[tmp]]-g;
      }
    }
    precomp1(n,x,y);
    REP(i,1,(1<<n)){
      int tv[m];
      rep(j,m)tv[j]=0;
      rep(j,n){
	if (((1<<j)&i) == 0)continue;
	rep(k,m)tv[k]=max(tv[k],price[j][k]);
      }
      precomp2(m,w,i,tv,weight);
      //cout << i <<" " << dp1[i] <<" " << dp2[i] << endl;
    }
    cout << solve(n,t) << endl;
  }
  return false;
}