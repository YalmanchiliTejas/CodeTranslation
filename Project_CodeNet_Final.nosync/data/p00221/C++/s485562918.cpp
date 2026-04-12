#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>
#include <cstdlib>

bool valid(const std::string &s, int k) {
  if (k % 15 == 0) {
    if (s != "FizzBuzz") return false;
  } else if (k % 3 == 0) {
    if (s != "Fizz") return false;
  } else if (k % 5 == 0) {
    if (s != "Buzz") return false;
  } else {
    if (s != std::to_string(k)) return false;
  }
  return true;
}

int testcase_ends() {
  size_t m;
  int n;
  scanf("%zu %d", &m, &n);
  if (m == 0 && n == 0)
    return 1;

  std::list<int> pp(m);  // players
  std::iota(pp.begin(), pp.end(), 1);
  auto it=pp.begin();
  for (int i=1; i<=n; ++i) {
    char buf[32];
    scanf("%s", buf);
    std::string s=buf;
    if (pp.size() <= 1) continue;

    if (!valid(s, i)) {
      auto tmp=it++;
      pp.erase(tmp);
    } else {
      ++it;
    }
    if (it == pp.end())
      it = pp.begin();
  }
  
  it = pp.begin();
  while (it != pp.end()) {
    printf("%d%c", *it, std::next(it)!=pp.end()? ' ':'\n');
    ++it;
  }
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

