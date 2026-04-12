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
#include<string>
#include<cstdlib>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
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
vector<vector<int>> G(10);
int N,M;
vector<bool> visited(10,false);
int dfs(int v, int cnt = 0){
  cnt++;
  if(cnt == N){
    return 1;
  }
  int res = 0;
  for(auto nv: G[v]){
    if(visited[nv]) continue;
    visited[nv] = true;
    res += dfs(nv,cnt);
    visited[nv] = false;
  }
  return res;
}

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  visited[0] = true;
  cout << dfs(0) << endl;
  return 0;
}
