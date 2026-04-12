#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

typedef long long ll;
typedef std::vector<int> vi;

void output() { std::cout << std::endl; }
void input() {}

template <class Head, class... Tail> void input(Head &&head, Tail &&... tail) {
  std::cin >> head;

  input(std::forward<Tail>(tail)...);
}

template <class Head, class... Tail> void output(Head &&head, Tail &&... tail) {
  std::cout << head;
  if (sizeof...(tail))
    std::cout << " ";

  output(std::forward<Tail>(tail)...);
}

int main() {
  do {

    ll n;
    input(n);
    if (!n)
      break;

    vi s(n);
    for (int &elem : s) {
      input(elem);
    }

    sort(s.begin(), s.end());
    output(std::accumulate(s.begin() + 1, s.end() - 1, 0) / (s.size() - 2));

  } while (true);
  return 0;
}
