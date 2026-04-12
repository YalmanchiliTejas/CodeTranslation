#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

string n;
vector<ll> s;
ll k;
vector<vector<vector<ll>>> table;
#define DP table[i][last][cnt]
ll dfs(ll i, ll last, ll cnt) {
  if (DP != -1) return DP;
  if (i == n.size()) {
    return DP = (n.size() - cnt) == k;
  }

  ll ans = 0;
  if (last) {
    ans += dfs(i + 1, true, cnt + (s[i] == 0));
    REP(j, s[i]) {
      ans += dfs(i + 1, false, cnt + (j == 0));
    }
  } else {
    REP(j, 10) {
      ans += dfs(i + 1, false, cnt + (j == 0));
    }
  }

  return DP = ans;
}

int main() {
  cin >> n >> k;
  REP(i, n.size()) s.push_back(n[i] - '0');
  table = vector<vector<vector<ll>>>(n.size() + 1,
      vector<vector<ll>>(2,
        vector<ll>(n.size() + 1, -1))
      );

  cout << dfs(0, true, 0);
}
