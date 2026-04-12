#include <algorithm>
#include <bitset>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
#include<iomanip>
namespace mp = boost::multiprecision;
using namespace std;
using ull = unsigned long long;
using ld = long double;
using lll = boost::multiprecision::cpp_int;
using ll = long long;
#define FOR(i, N) for(ll i = 0; i < N; ++i)

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
// using int = ll;
template <typename T>
T gcd(T m, T n) {
    if(n == 0)
        return abs(m);
    return (gcd(n, m % n));
}
void putYN(bool b) {
    if(b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
ll combi(ll n, ll k) {
    ll r = 1, rr = 1;
    for(ll i = 0; i < k; ++i) {
        r *= (n - i);
        rr *= (i + 1);
        // r %= 1000000007;
        // rr %= 1000000007;
    }
    r /= rr;
    // r %= 1000000007;
    return r;
}
int main(){
  ll N,K;
  string S;
  cin>>S>>K;
  reverse(S.begin(),S.end());
  vector<vector<ll>> dp(S.size(),vector<ll>(8,0));//溢れない,0,1,2,3,
  dp[0][0]=1;
  int c=S[0]-'0';
  dp[0][1]=c;
  dp[0][1+4]=9-c;  
  for(ll i=1;i<S.size();++i){
    c = S[i]-'0';
    FOR(j,2){
      FOR(k,4){
        if(j==0){
          if(c!=0){
            dp[i][k]+=dp[i-1][k];
            dp[i][k]+=dp[i-1][4+k];
          }else{
            dp[i][k]+=dp[i-1][k];
            dp[i][4+k]+=dp[i-1][4+k];
          }
        }else{
          
        }
        if(k!=0){
          if(j==0){
            dp[i][k]+=dp[i-1][k-1]*(c);
            if(c!=0){
              dp[i][k]+=dp[i-1][4+k-1]*(c-1);
            }
          }else{
            dp[i][4+k]+=dp[i-1][k-1]*(9-c);
            if(c!=0){
              dp[i][4+k]+=dp[i-1][4+k-1]*(9-c+1);
            }else{
              dp[i][4+k]+=dp[i-1][4+k-1]*(9);
            }
          }
        }
      }
    }
  }
  cout<<dp[S.size()-1][K]<<endl;
  return 0;
}