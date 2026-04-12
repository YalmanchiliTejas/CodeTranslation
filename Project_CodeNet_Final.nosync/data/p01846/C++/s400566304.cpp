#include <cstdio>
#include <cstdint>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

std::vector<std::string> decode(const std::string& s) {
  std::vector<std::string> res(1);
  for (size_t i = 0; s[i]; ++i) {
    if (isdigit(s[i])) {
      res.back() += std::string(s[i]-'0', '.');
    } else if (s[i] == 'b') {
      res.back() += "b";
    } else if (s[i] == '/') {
      res.emplace_back();
    }
  }
  // for (size_t i = 0; i < res.size(); ++i)
  //   fprintf(stderr, "%s\n", res[i].c_str());

  return res;
}

std::string encode(const std::vector<std::string>& z) {
  std::string res;
  for (const auto& zi: z) {
    size_t dots = 0;
    for (size_t i = 0; i <= zi.length(); ++i) {
      if (zi[i] == '.') {
        ++dots;
      } else {
        if (dots) res += dots+'0';
        dots = 0;
        if (zi[i] == 'b') res += 'b';
      }
    }
    res += '/';
  }
  assert(res.back() == '/');
  res.pop_back();
  return res;
}

int testcase_ends() {
  char buf[131072];
  scanf("%s", buf);
  std::string s = buf;
  if (s == "#") return 1;

  auto z = decode(s);
  size_t a, b, c, d;
  scanf("%zu %zu %zu %zu", &a, &b, &c, &d);

  --a;
  --b;
  --c;
  --d;
  assert(z[a][b] == 'b');
  assert(z[c][d] == '.');
  std::swap(z[a][b], z[c][d]);

  printf("%s\n", encode(z).c_str());
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

