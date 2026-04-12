/*input
5
9 5 6 8 4
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, mm = 0, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    if (a >= mm) {
      mm = a;
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
} 