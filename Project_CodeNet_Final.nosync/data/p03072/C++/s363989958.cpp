/* https://atcoder.jp/contests/abc124/tasks/abc124_b */

#include <iostream>
#include <vector>

/* {{{ Variables */
int N;
std::vector<int> H;
/* }}} */

int main(int argc, char *argv[])
{
  /* {{{ Input */
  std::cin >> N;

  H = std::vector<int>(N);

  for (int& e: H)
    std::cin >> e;
  /* }}} */

  /* {{{ Output */
  int num = 0;
  int max_h = 0;

  for (int& e: H) {
    if (e >= max_h) {
      max_h = e;
      num++;
    }
  }

  std::cout << num << std::endl;
  /* }}} */

  return 0;
}
