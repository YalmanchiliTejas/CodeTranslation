#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e6 + 5;

ll K;
vector < ll > v;
ll dp[105][2][105];

ll solve(ll idx, ll smaller, ll k){
  if(idx == v.size()){
    if(k == K) return 1;
    return 0;
  }

  if(dp[idx][smaller][k] != -1) return dp[idx][smaller][k];

  ll ans = 0;
  if(smaller){
    for(int i = 0; i < 10; i++){
      ans += solve(idx + 1, 1, i == 0 ? k : k + 1);
    }
  }else{
    for(int i = 0; i <= v[idx]; i++){
      ans += solve(idx + 1, i == v[idx] ? 0 : 1, i == 0 ? k : k + 1);
    }
  }

  dp[idx][smaller][k] = ans;
  return ans;
}

ll preprocess(string s){
  ll n = s.length();
  v.resize(n);
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++){
    v[i] = s[i] - '0';
  }

  return solve(0, 0, 0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string n;
  cin >> n;
  cin >> K;
  cout << preprocess(n);
}
