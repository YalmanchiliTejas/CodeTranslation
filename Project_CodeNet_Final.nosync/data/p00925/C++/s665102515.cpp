#include <cstdio>
#include <cstdint>
#include <cassert>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> ops = {"+-", "*"};

intmax_t parse_int(std::string const& s, size_t& i) {
  intmax_t res = s[i]-'0';
  while (isdigit(s[++i])) res = res*10 + s[i]-'0';
  return res;
}

intmax_t parse(std::string const& s, size_t& i, size_t preced = 0) {
  if (preced == ops.size()) {
    if (isdigit(s[i])) return parse_int(s, i);
    assert(false);
  }

  intmax_t res = parse(s, i, preced+1);
  while (i < s.length()) {
    char op = s[i];
    if (!std::count(ops[preced].begin(), ops[preced].end(), op)) break;
    intmax_t tmp = parse(s, ++i, preced+1);
    if (op == '+') {
      res += tmp;
    } else if (op == '-') {
      res -= tmp;
    } else if (op == '*') {
      res *= tmp;
    }
  }
  return res;
}

int main() {
  char buf[131072];
  scanf("%s", buf);
  std::string s = buf;

  intmax_t d;
  scanf("%jd", &d);

  intmax_t res1, res2;
  {
    size_t i = 0;
    res1 = parse(s, i);
  }
  ops = std::vector<std::string>{"+-*"};
  {
    size_t i = 0;
    res2 = parse(s, i);
  }

  // fprintf(stderr, "%jd %jd\n", res1, res2);

  if (res1 == d) {
    if (res2 == d) {
      puts("U");
    } else {
      puts("M");
    }
  } else {
    if (res2 == d) {
      puts("L");
    } else {
      puts("I");
    }
  }
}

