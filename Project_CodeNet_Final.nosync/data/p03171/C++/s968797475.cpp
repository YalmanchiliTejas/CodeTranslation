#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  vector<vector<vector<ll>>>memo(n,vector<vector<ll>>(n+1,vector<ll>(2,-1e18)));
  function<ll(ll,ll,bool)>dfs=[&](ll l,ll r,bool f){
    ll res;
    if(memo[l][r][f]>-1e18)return memo[l][r][f];
    if(r-l==1){
      if(f)return memo[l][r][f]=a[l];
      return memo[l][r][f]=-a[l];
    }
    if(f){//maximize
      res=-1e18;
      chmax(res,dfs(l,r-1,!f)+a[r-1]);
      chmax(res,dfs(l+1,r,!f)+a[l]);
    }
    else{
      res=1e18;
      chmin(res,dfs(l,r-1,!f)-a[r-1]);
      chmin(res,dfs(l+1,r,!f)-a[l]);
    }
    return memo[l][r][f]=res;
  };
  cout<<dfs(0,n,1)<<endl;

  return 0;

}
