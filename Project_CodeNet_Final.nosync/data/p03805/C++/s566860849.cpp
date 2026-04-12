#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
/*
void chmin(ll a, ll b){if (a>b){a = b; return true;}return false;}
void chmax(ll a, ll b){if (a<b){a = b; return true;}return false;}
*/

const ll MOD = 1000000007;
const ll INF = 9999999999;

void dfs(Graph &G, int v, vector<bool> &seen, int &ans){
  seen.at(v) = true;
  bool end = true; // 行けるところが無くなったらtrue
  for (auto nv : G.at(v)){
    if (seen.at(nv)) continue;
    dfs(G, nv, seen, ans);
    end = false;
  }
  if (end){
    bool ok = true;
    for (auto vs : seen){
      ok = ok && vs;
    }
    if (ok) ans++;
  }
  seen.at(v) = false;
  return;
}

int main() {
  int N,M; cin >>N >>M;
  Graph G(N);
  for (int i=0; i<M; i++){
    int a,b; cin >>a >>b;
    a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  vector<bool> seen(N, false);
  int ans = 0;
  dfs(G, 0, seen, ans);
  cout <<ans <<endl;
}