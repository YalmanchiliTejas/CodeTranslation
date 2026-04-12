#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define derr if(1) cerr
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

ll choose(int n, int k) {
  if(k < 0) return 0;
  ll ret = 1;
  for(int i = 0; i < k; i++) {
    ret *= n-i;
    ret /= i+1;
  }
  return ret;
}

ll solve(string s, int k) {
  if(k == 0) return 1;
  if(sz(s) == 0) return 0;
  ll ret = 0;
  for(char c = '0'; c <= '9'; c++) {
    int nonzero = k - (c != '0');
    if(s[0] == c) {
      ret += solve(s.substr(1), nonzero);
      break;
    }
    ll cand = choose(sz(s)-1, nonzero);
    for(int a = 0; a < nonzero; a++) cand *= 9;
    ret += cand;
  }
  return ret;
}

void solve() {
  string s;
  int k;
  cin >> s >> k;
  cout << solve(s, k) << "\n";
}
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
