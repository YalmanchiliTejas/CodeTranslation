#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

ll d;
string s;

ll dp[MAXN][2][105];

ll solve(ll ind, ll smaller, ll rem){
  if(ind == s.size()){
    if(rem == 0) return 1;
    return 0;
  }

  if(dp[ind][smaller][rem] != -1){
    return dp[ind][smaller][rem];
  }

  ll ans = 0;
  if(smaller){
    for(int i = 0; i < 10; i++){
      ans = (ans + solve(ind + 1, 1, (rem + i) % d)) % mod;
    }
  }else{
    ll limit = s[ind] - '0';
    for(int i = 0; i <= limit; i++){
      ans = (ans + solve(ind + 1, i == limit ? 0 : 1, (rem + i) % d)) % mod;
    }
  }

  dp[ind][smaller][rem] = ans;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> s;
  cin >> d;

  for(int i = 0; i < MAXN; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 105; k++) dp[i][j][k] = -1;
    }
  }

  ll ans = (solve(0, 0, 0) - 1 + mod) % mod;
  cout << ans << endl;
}
