#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;
  int m = 0;
  int ans = 0;
  REP(i, N) {
    int H;
    cin >> H;
    if (m <= H) ans++;
    m = max(m, H);
  }
  cout << ans << endl;
}

