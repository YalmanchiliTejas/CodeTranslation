#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string stringify(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}

int main() {
  for (;;) {
    int m, n;
    cin >> m >> n;
    if (!m && !n) return 0;
    bool ps[1000];
    fill(ps, ps+m, true);
    for (int i = 1, j = 0, p = m; i <= n; i++) {
      string s;
      cin >> s;
      if (p == 1) continue;
      while (!ps[j]) {
        j++;
        j %= m;
      }
      if (i % 15 == 0 && s != "FizzBuzz" ||
          i % 15 != 0 && i % 3 == 0 && s != "Fizz" ||
          i % 15 != 0 && i % 5 == 0 && s != "Buzz" ||
          i % 3 != 0 && i % 5 != 0 && s != stringify(i)) {
        ps[j] = false;
        p--;
      }
      j++;
      j %= m;
    }
    int s = 0;
    while (!ps[s]) s++;
    cout << s + 1;
    for (int i = s + 1; i < m; i++)
      if (ps[i])
        cout << ' ' << i + 1;
    cout << endl;
  }
}