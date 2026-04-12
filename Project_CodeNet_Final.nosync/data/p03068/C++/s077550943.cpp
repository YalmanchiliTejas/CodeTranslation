/* https://tenka1-2019-beginner.contest.atcoder.jp/tasks/tenka1_2019_b */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* {{{ Variables */
int N, K;
string S;
/* }}} */

int main(int argc, char *argv[])
{
  /* {{{ Input */
  cin >> N >> S >> K;
  /* }}} */

  /* {{{ Output */
  char s = S.at(K-1);

  for (char e: S) {
    cout << (e == s ? s : '*');
  }
  cout << endl;
  /* }}} */

  return 0;
}
