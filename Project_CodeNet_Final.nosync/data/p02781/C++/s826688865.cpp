#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define MOD 1000000007

ll dp[200][2][2][7];

int main(){
  clr(dp,0);
  string s1;
  ll K;
  cin>>s1>>K;
  string s;
  rep(i,0,200-(int)s1.sz){
    s += "0";
  }
  rep(i,0,s1.sz){
    s += s1[i];
  }
  dp[0][0][0][0] = 1;
  rep(i,1,200){
    ll a = s[i]-'0';
    //rep(j,0,2){
      //rep(k,0,2){
        rep(l,0,5){
          rep(m,0,10){
            if(m==a){
              if(m!=0){
                if(l>4)continue;
                dp[i][0][1][l+1] += dp[i-1][0][0][l];
                dp[i][0][1][l+1] += dp[i-1][0][1][l];
                dp[i][1][1][l+1] += dp[i-1][1][0][l];
                dp[i][1][1][l+1] += dp[i-1][1][1][l];
              }
              else{
                dp[i][0][0][l] += dp[i-1][0][0][l];
                dp[i][0][1][l] += dp[i-1][0][1][l];
                dp[i][1][0][l] += dp[i-1][1][0][l];
                dp[i][1][1][l] += dp[i-1][1][1][l];
              }
            }
            if(m<a){
              if(m!=0){
                if(l>4)continue;
                dp[i][1][1][l+1] += dp[i-1][0][0][l];
                dp[i][1][1][l+1] += dp[i-1][0][1][l];
                dp[i][1][1][l+1] += dp[i-1][1][0][l];
                dp[i][1][1][l+1] += dp[i-1][1][1][l];
              }
              else{
                dp[i][1][0][l] += dp[i-1][0][0][l];
                dp[i][1][1][l] += dp[i-1][0][1][l];
                dp[i][1][0][l] += dp[i-1][1][0][l];
                dp[i][1][1][l] += dp[i-1][1][1][l];
              }
            }
            if(m>a){
              if(m!=0){
                if(l>4)continue;
                dp[i][1][1][l+1] += dp[i-1][1][0][l];
                dp[i][1][1][l+1] += dp[i-1][1][1][l];
              }
              else{
                dp[i][0][0][l] += dp[i-1][0][0][l];
                dp[i][0][1][l] += dp[i-1][0][1][l];
                dp[i][1][0][l] += dp[i-1][1][0][l];
                dp[i][1][1][l] += dp[i-1][1][1][l];
              }
            }
          }
        }
      //}
    //}
  }
  cout << dp[199][0][1][K]+dp[199][1][1][K] << endl;
  return 0;
}