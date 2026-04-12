#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

vector<vector<int>> g;
vector<int> dp;
vector<vector<int>> len;

void predfs(int now,int par){
    int res=0;
    for(auto nex:g[now]) if(nex!=par){
        predfs(nex,now);
        chmax(res,dp[nex]+1);
        len[now].push_back(dp[nex]+1);
    }
    dp[now]=res;
}

void dfs(int now,int par,int pval){
    if(par!=-1) len[now].push_back(pval);
    sort(len[now].rbegin(),len[now].rend());

    for(auto nex:g[now]) if(nex!=par){
        int neco=len[now][0];
        if(neco==dp[nex]+1){
            if(len[now].size()>1) neco=len[now][1];
            else neco=0;
        }
        dfs(nex,now,neco+1);
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;
  g.resize(N);
  rep(i,N-1){
      int a,b;
      cin>>a>>b;
      a--;b--;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  dp.resize(N,0);
  len.resize(N);
  predfs(0,-1);

  dfs(0,-1,-1);

  int lim=0;
  for(int i=0;i<N;i++){
      if(len[i].size()<=2) continue;
      int fir=len[i][0];
      int sec=len[i][2];
      if(fir==sec) sec--;
      chmax(lim,fir+sec);
  }

  string ans(N,'1');
  rep(i,lim) ans[i]='0';
  ans[0]='1';ans[1]='1';
  cout<<ans<<endl;


  return 0;
}

