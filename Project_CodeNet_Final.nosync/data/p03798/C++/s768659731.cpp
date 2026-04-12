#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vll = vector<ll>;

void solve();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)

#define inl(...)  \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)

#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__);

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}

void out() {
  cout << endl;
}
template <typename T, class... U>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u))
    cout << " ";
  out(u...);
}

#define rep(i, n) for (long long i = 0; i < n; i++)

void solve();
#ifndef ONLINE_JUDGE
#include "./lib.hpp"
#endif

ll sheep_or_wolf(ll conf, ll at) {
    return (conf >> at) & 1LL;
}

bool is_consistent_at(string& s, string& conf, ll at) {
    bool must_same = (conf[at] == 'S' && s[at] == 'o') || (conf[at] == 'W' && s[at] == 'x');
    
    char next = conf[(at + 1) % s.size()];
    char prev = conf[(at + s.size() - 1) % s.size()];
    return (must_same && next == prev) || (!must_same && next != prev);
}

bool fill(string& s, string& conf) {
    for (ll i = 1; i < s.size() - 1; i++) {
        bool must_same = (conf[i] == 'S' && s[i] == 'o') || (conf[i] == 'W' && s[i] == 'x');
        if (must_same)
            conf[i + 1] = conf[i - 1];
        else
            conf[i + 1] = conf[i - 1] == 'W' ? 'S' : 'W';
    }

    return is_consistent_at(s, conf, 0) && is_consistent_at(s, conf, s.size() - 1);
}

void solve() {
    ini(N);
    ins(s);

    string conf(s.size(), 'U');
    
    for (auto cand: {"SS", "SW", "WS", "WW"}) {
       conf[0] = cand[0]; 
       conf[1] = cand[1]; 
       if (fill(s, conf)) {
           out(conf);
           return;
       }
    }

    out(-1);
}
