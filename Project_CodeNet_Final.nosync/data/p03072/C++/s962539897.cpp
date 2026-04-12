#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  vector<int> H(N, 0);
  for (int i = 0; i < N; i++) {
    scanf("%d", &H.at(i));
  }

  int ans = 1;
  bool can_watch_sea = true;
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (H.at(i) < H.at(j)) can_watch_sea = false;
    }
    if (can_watch_sea) {
      ans++;
    } else {
      can_watch_sea = true;
    }
  }

  printf("%d", ans);
  return 0;
}