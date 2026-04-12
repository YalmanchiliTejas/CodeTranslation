// https://atcoder.jp/contests/abc049/tasks/abc049_a

#include <iostream>
using namespace std;

int main()
{
  /* Magic word */
  cin.tie(0);
  ios::sync_with_stdio(false);
  /* ---------- */

  char c;
  string v = "aieou";

  cin >> c;

  string result = v.find(c) != string::npos ? "vowel" : "consonant";

  cout << result << "\n";

  return 0;
}
