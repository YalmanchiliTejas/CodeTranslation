#include <cstdio>
#include <string>

using namespace std;

int main() {
  char t[9];
  scanf("%s", t);
  string s = string(t);
  puts(s == "AAA" || s == "BBB" ? "No" : "Yes");
}
