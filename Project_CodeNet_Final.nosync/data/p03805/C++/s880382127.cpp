#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  int n,m;
  cin >> n >> m;
  ll dp[(1<<n)][n];
  ll ndp[(1<<n)][n];
  
  rep(i,(1<<n)) rep(j,n){
    dp[i][j]=0;
    ndp[i][j]=0;    
  }
  dp[1][0]=1;
  ndp[1][0]=1;
  vector<int> g[n];
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  rep(h,n-1){
    rep(i,(1<<n)) rep(j,n){
      if(i&1){
    	for(auto l:g[j]){
	      if(i&(1<<l)) continue;
	      //cout << i << " " << j << " " << l <<endl;
	      ndp[i|(1<<l)][l]+=dp[i][j];
	    }
      }
    }
    //cout << ndp[3][1] << endl;
    //    swap(dp, ndp);
    rep(i,(1<<n)) rep(j,n) dp[i][j]=ndp[i][j];
  }

  ll ans=0;
  rep(j,n) ans +=dp[(1<<n)-1][j];
  cout << ans << endl;
  
  return 0;

}
