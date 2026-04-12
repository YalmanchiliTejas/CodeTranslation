#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;

vector<ll> A;
unordered_map<ll, ll> memo;

ll rec(ll from, ll to, ll turn) {
  ll p =  from * 10000 + to;
  if (memo.count(p)) return memo[p];
  if (from == to) return turn == 0 ? A[from] : -A[from];
  ll foo = rec(from + 1, to, 1 - turn);
  if (turn == 0) foo += A[from];
  else foo -= A[from];
  ll bar = rec(from, to - 1, 1 - turn);
  if (turn == 0) bar += A[to];
  else bar -= A[to];
  ll ans = turn == 0 ? max(foo, bar) : min(foo, bar);
  memo[p] = ans;
  return ans;
}

void solve() {
  ll N;
  cin >> N;
  rep (i, N) {
    ll tmp;
    cin >> tmp;
    A.push_back(tmp);
  }
  cout << rec(0, N-1, 0) << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  solve();
  return 0;
}
