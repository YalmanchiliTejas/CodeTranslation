#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll inf = numeric_limits<ll>::max()/3;

int count_bit(int b){
  int cnt = 0;
  while(b > 0){
    if(b & 1)
      ++cnt;
    b >>= 1;
  }
  return cnt;
}


int main(void){
  int n,m;
  cin >> n >> m;
  vector< vector<int> > G(n);
  for(int i = 0;i < m;++i){
    int a,b;
    cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll dp[10][300];
  fill(dp[0], dp[0]+10*300, 0LL);
  dp[0][1] = 1;
  for(int k = 1;k < n;++k){
    for(int i = 0;i < n;++i){
      for(int b = 0;b < (1 << n);++b){
        if(count_bit(b) == k){
          for(int j : G[i]){
            if(!(b & (1 << j))){
              dp[j][b | (1 << j)] += dp[i][b];
            }
          }
        }
      }
    }
  }
  ll res = 0;
  for(int i = 0;i < n;++i){
    res += dp[i][(1 << n)-1];
  }
  cout << res << endl;
  return 0;
}

