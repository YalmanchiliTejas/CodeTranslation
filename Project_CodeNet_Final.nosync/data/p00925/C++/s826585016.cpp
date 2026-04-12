#include <cstdio>
#include <cctype>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int parse(
    const std::string &s, size_t &i, const std::vector<std::string> &ops,
    size_t preced=0) {

  if (preced == ops.size()) {
    assert(isdigit(s[i]));
    return s[i++]-'0';
  }
  int res=parse(s, i, ops, preced+1);
  while (i < s.length()) {
    char op=s[i];
    if (!std::count(ops[preced].begin(), ops[preced].end(), op)) break;
    int tmp=parse(s, ++i, ops, preced+1);
    if (op == '+') res += tmp;
    if (op == '*') res *= tmp;
  }
  return res;
}

int main() {
  char buf[32];
  scanf("%s", buf);
  std::string s=buf;
  int bob;
  scanf("%d", &bob);

  int st=0;
  {
    size_t i=0;
    int res=parse(s, i, {"+", "*"});
    if (res == bob) st |= 1;
  }
  {
    size_t i=0;
    int res=parse(s, i, {"+*"});
    if (res == bob) st |= 2;
  }
  printf("%c\n", "IMLU"[st]);
}

