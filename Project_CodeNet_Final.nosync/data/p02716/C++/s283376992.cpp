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

const ll INF=1e18;

ll solve(int N,vector<ll> &A){
  vector<ll> lef(N+1,0),rig(N+1,0);
  for(int i=0;i<N;i+=2){
      lef[i]=A[i];
      if(i-2>=0) lef[i]+=lef[i-2];
  }
  for(int i=N-1;i>=0;i-=2){
      rig[i]=A[i];
      if(i+2<N) rig[i]+=rig[i+2];
  }

  ll res=max(lef[N-2],rig[1]);
  for(int i=0;i+3<N;i+=2) chmax(res,lef[i]+rig[i+3]);
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  if(N%2==0){
    cout<<solve(N,A)<<endl;
    return 0;
  }

  vector<vector<ll>> result(2,vector<ll> (N,0));
  for(int k=0;k<2;k++){
    ll all=0;
    ll ma=0;
    for(int i=1;i<N;i+=2){
      result[k][i]=max(all+A[i-1],ma+A[i]);
      ma=result[k][i];
      all+=A[i-1];
    }
    reverse(A.begin(),A.end());
  }
  reverse(result[1].begin(),result[1].end());

  ll ans=max(result[0][N-2],result[1][1]);
  for(int i=2;i+1<N;i+=2){
    chmax(ans,result[0][i-1]+result[1][i+1]);
  }
  cout<<ans<<endl;

  return 0;
}
