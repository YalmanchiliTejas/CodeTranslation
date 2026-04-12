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
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,X,M;
  cin>>N>>X>>M;

  vector<vector<int>> nxt(M,vector<int> (40));
  vector<vector<ll>> sum(M,vector<ll> (40,0));
  for(ll i=0;i<M;i++){
    nxt[i][0]=(i*i)%M;
    sum[i][0]=i;
  }
  for(int k=1;k<40;k++){
    for(int i=0;i<M;i++){
      nxt[i][k]=nxt[nxt[i][k-1]][k-1];
      sum[i][k]=sum[i][k-1]+sum[nxt[i][k-1]][k-1];
    }
  }

  ll now=X;
  ll ans=0;
  for(ll k=39;k>=0;k--){
    if(N&(1ll<<k)){
      ans+=sum[now][k];
      now=nxt[now][k];
    }
  }
  cout<<ans<<endl;

  return 0;
}
