#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

vector<ll> size(51),patty(51);

ll dfs(ll N,ll X){
  if(N == 0) return 1;
  if(X <= 1) return 0;
  if(X <= 1+size[N-1]) return dfs(N-1,X-1);
  if(X == 2+size[N-1]) return patty[N-1] + 1;
  if(X < 2*size[N-1]+3) return patty[N-1] + 1 + dfs(N-1,X-2-size[N-1]);
  return patty[N-1]*2 + 1;
}

int main(){
  ll N,X;
  cin >> N >> X;
  size[0] = 1;
  patty[0] = 1;
  for(int i=1; i<=50; i++){
    size[i] = size[i-1]*2 + 3;
    patty[i] = patty[i-1]*2 + 1;
  }
  cout << dfs(N,X) << endl;
  return 0;
}
