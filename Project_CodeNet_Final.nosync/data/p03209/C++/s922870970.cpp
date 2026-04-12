#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <boost/math/common_factor_rt.hpp>
using namespace std;
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long

ll solve(ll b[], ll p [], ll N, ll X, ll sum){
  if(N==0) return sum+1;
  if(X==1) return sum;
  else if(X==b[N-1]+2) return sum + p[N-1] + 1;
  else if(X==2*b[N-1]+3) return sum + 2*p[N-1] + 1;
  else if(1<X && X<b[N-1]+2) return solve(b, p, N-1, X-1, sum);
  else return solve(b, p, N-1, X-2-b[N-1], sum+p[N-1]+1);
}

int main(){
  ll N, X;
  cin >> N >> X;
  ll b[51];
  ll p[51];
  ll sum = 0;
  
  b[0] = 1;
  p[0] = 1;
  rep(i, 50) b[i+1] = b[i]*2+3, p[i+1] = 2*p[i]+1;
  
  cout << solve(b, p, N, X, sum) << endl;
  
    
}