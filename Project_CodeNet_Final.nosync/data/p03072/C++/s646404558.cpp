#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  int N;
  cin >> N;
  int h[N];
  for (int i = 0; i < N; i++) cin >> h[i];

  int tmp = h[0];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (tmp <= h[i]) {
      ans++;
      tmp = h[i];
    }
  }

  cout << ans << endl;
  return 0;
}
