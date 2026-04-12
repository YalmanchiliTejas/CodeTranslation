#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

constexpr int lim = 50;
ll s[lim+1], p[lim+1];

void init(){
  s[0] = 1; p[0] = 1;
  FOR(i, 1, lim+1){
    s[i] = 2 * s[i-1] + 3;
    p[i] = 2 * p[i-1] + 1;
  }
}

ll solve(ll n, ll x){
  if(x == 1){
    return (n == 0)? p[0]: 0;
  }
  else if(x < s[n-1] + 2){
    return solve(n-1, x-1);
  }
  else if(x == s[n-1] + 2){
    return p[n-1] + 1;
  }
  else if(x < 2 * s[n-1] + 3){
    return p[n-1] + 1 + solve(n-1, x-(s[n-1]+2));
  }
  else{
    return p[n];
  }
}

int main(){
  ll n, x; cin >> n >> x;

  init();

  cout << solve(n, x) << endl;

  return 0;
}
