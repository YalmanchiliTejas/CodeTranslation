#include <bits/stdc++.h>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

// print(x, y, z);
// printVec(va.begin(), va.end());
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

int main(int argc, char* argv[])
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N;
  std::cin >> N;

  std::vector<std::map<char, ll>> M(N);
  std::vector<std::string> vs(N, "");
  for (ll i = 0; i < N; i++) {
    std::cin >> vs[i];
    std::string::iterator it;
    for(it = vs[i].begin(); it != vs[i].end(); it++) {
      M[i][*it]++;
    }
  }

  std::string ans;
  for (ll c = 'a'; c <= 'z'; c++) {
    ll min_val = INF;
    for (ll i = 0; i < N; i++) {
      min_val = std::min(min_val, M[i][c]);
    }
    ans += std::string(min_val, c);
  }

  print(ans);
  return 0;
}
