#include <cstdio>
#include <set>
#include <string>
#include <algorithm>

int testcase_ends() {
  char buf[64];
  scanf("%s", buf);
  std::string s = buf;
  if (s == "#") return 1;

  std::string r0 = "yuiophjklnm";
  std::set<char> r(r0.begin(), r0.end());
  int res = -1;
  int last = -1;
  for (char c: s) {
    int cur = r.count(c);
    if (last != cur) ++res;
    last = cur;
  }
  printf("%d\n", res);
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

