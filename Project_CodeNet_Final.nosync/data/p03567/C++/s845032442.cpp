#include <bits/stdc++.h>

using namespace std;
 
// macro
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define ll long long
#define ull unsigned long long
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define SORT(ary) sort(begin(ary), end(ary))
#define VL vector<ll>
#define VVL vector<VL>
#define PL pair<ll, ll>
#define VC vector<char>
#define VVC vector<VC>

// Factorial
// need init
ll factorial_memo[5001];
ll factorial(ll n) {
  factorial_memo[0] = 1;
  if(factorial_memo[n] != -1) return factorial_memo[n];
  factorial_memo[n] = (factorial(n-1) * n) % MOD;
  return factorial_memo[n];
}
 
// Combination(nCr)
// need init
ll nCr_memo[5001][5001];
ll nCr(ll n, ll r) {
  if(r*2 > n) r = n-r;
  if(r == 1) return n;
  if(r == 0) return 1;
  if(nCr_memo[n][r] != -1) return nCr_memo[n][r];
  nCr_memo[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)) % MOD;
  return nCr_memo[n][r];
}

ll bridgeDfs(VVL& g, vector<PL>& res, ll v, ll& count, ll from, VL& low, VL& pre) {
  pre[v] = count++;
  low[v] = pre[v];
  for(auto to:g[v]) {
    if (pre[to] == -1) {
      low[v] = min(low[v], bridgeDfs(g, res, to, count, v, low, pre));
      if(low[to] == pre[to]) res.push_back(make_pair(v, to));
    } else {
      if(from == to) continue;
      low[v] = min(low[v], low[to]);
    }
  }
  return low[v];
}

vector<PL> bridges(VVL& g, ll N) {
  vector<PL> res;
  if (N > 0) {
    VL low(N, -1);
    VL pre(N, -1);
    ll count = 0;
    bridgeDfs(g, res, 0, count, -1, low, pre);
  }
  return res;
}

void solve() {
    string s;
    cin >> s;
    REP(i, s.size()-1) {
        if(s.at(i) == 'A' && s.at(i+1) == 'C') {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No";
}



int main() {
  // init
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
