#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int L;
string S, T;
string repeat(string &pat, int num) {
  string o = "";
  rep(_, num) o += pat;
  return o;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> L >> S >> T;
  vector<P> cand;
  for (int x=0; x*S.length()<=L; x++) {
    int y = L-x*S.length();
    if (y % T.length()) continue;
    y /= T.length();
    cand.pb(P(x, y));
  }
  assert(cand.size());
  string s = "~";
  s = min(s, repeat(S, cand.front()._1) + repeat(T, cand.front()._2));
  s = min(s, repeat(T, cand.front()._2) + repeat(S, cand.front()._1));
  s = min(s, repeat(S, cand.back()._1) + repeat(T, cand.back()._2));
  s = min(s, repeat(T, cand.back()._2) + repeat(S, cand.back()._1));
  cout << s << "\n";
  return 0;
}
