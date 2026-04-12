#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

template<class T, class Cond>
struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  bool operator()(T& a, const T& b) const {
    if(cond(a, b)) { a = b; return true; }
    return false;
  }
};
template<class T, class Cond>
chain<T, Cond> make_chain(Cond cond) { return chain<T, Cond>(cond); }

vector<vector<i64>> G;

vector<i64> match;

bool dfs(i64 v, i64 f) {
  for(auto t: G[v]) {
    if(t == f) continue;
    if(!dfs(t, v)) {
      return false;
    }
  }

  if(match[v] == 0) {
    if(0 <= f && match[f] == 0) {
      match[v] = 1;
      match[f] = 1;
      return true;
    }
    else {
      return false;
    }
  }
  return true;
}

int main() {
  i64 N;
  cin >> N;
  G.resize(N);
  rep(i,0,N - 1) {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  match.resize(N);

  if(dfs(0, -1)) {
    cout << "Second" << endl;
  }
  else {
    cout << "First" << endl;
  }
}
