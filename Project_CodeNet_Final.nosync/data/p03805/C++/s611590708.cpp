#include <bits/stdc++.h>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

const ll MAX_N = 8;
ll N, M;
std::vector< std::vector<ll> > vedge(MAX_N, std::vector<ll>(MAX_N, INF));

void print(){ std::cout << std::endl; }
template <typename Head> void print(Head&& head) { std::cout << head << std::endl; }
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail)
{
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...); // or print(tail...);
}
template<typename Iterator> void printVec(Iterator begin, Iterator end)
{
  for (Iterator it = begin; it != end; it++) {
    std::cout << "[" << it - begin << "] " << *it << " ";
    if ((it - begin) % 20 == 19 || it == end - 1) { std::cout << std::endl; }
  }
}

bool is_ok(std::vector<ll>& path)
{
  if (path[0] != 0) return false;

  bool judge = true;
  for (ll i = 0; i < N - 1; i++) {
    if (vedge[path[i]][path[i+1]] == INF) {
      judge = false;
    }
  }
  return judge;
}

int main(int argc, char* argv[])
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    ll a, b;
    std::cin >> a >> b;
    a--; b--;
    vedge[a][b] = 1;
    vedge[b][a] = 1;
  }

  std::vector<ll> path(N, 0LL);
  for (ll i = 0; i < N; i++) {
    path[i] = i;
  }

  ll ans = 0LL;
  do {
    if (is_ok(path)) {
      //printVec(path.begin(), path.end());
      ans++;
    }
  } while (std::next_permutation(path.begin(), path.end()));

  std::cout << ans << std::endl;
  return 0;
}
