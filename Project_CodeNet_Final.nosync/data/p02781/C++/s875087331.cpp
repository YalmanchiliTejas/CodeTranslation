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
#define rrepi(i,a,b) for(ll i=(ll)(b-1);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;cin>>n;
  ll k;cin>>k;
  ll l=n.length();
  vector<vector<ll>>dp(2,vector<ll>(5));
  dp[1][0]=1;
  dp[1][1]=n[0]-'0'-1;
  dp[0][1]=1;

  repi(i,1,l){
    auto tdp=dp;
    //lesser
    rep(j,4){
      tdp[1][j+1]+=dp[1][j]*9;
    }
    if(n[i]!='0'){
      rep(j,4){
        if(dp[0][j]==1){
          tdp[0][j+1]=1;
          tdp[0][j]--;
          tdp[1][j+1]+=n[i]-'0'-1;
          tdp[1][j]++;
        }
      }
    }
    dp=tdp;
  }
  cout<<dp[0][k]+dp[1][k]<<endl;


  return 0;

}
