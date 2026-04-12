#include <bits/stdc++.h>
#define pr(s) std::cout << s << std::endl
#define prb(s) std::cout << s
using namespace std;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);


  int n;
  int max = 0;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (h >= max) {
      count++;
      max = h;
    }
  }

  pr(count);

  return 0;
}
