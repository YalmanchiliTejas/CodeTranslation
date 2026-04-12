#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  int N;
  cin >> N;
  int x[N], tmp[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", x + i);
    tmp[i] = x[i];
  }

  sort(tmp, tmp + N);
  int l = tmp[N/2-1];
  int r = tmp[N/2];
  
  for (int i = 0; i < N; i++) {
    if (x[i] <= l) {
      cout << r << endl;
    } else {
      cout << l << endl;
    }
  }
  return 0;
}
