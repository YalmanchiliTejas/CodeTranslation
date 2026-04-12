#include <bits/stdc++.h>

int N;
const int MAX_N = 100005;
int vals[MAX_N];

int main() {
  scanf("%d", &N);
  std::set<std::pair<int, int>> s;
  for (int i = 0; i < N; ++i) {
    scanf("%d", vals + i);
  }
  int colcount = 0;
  for (int i = 0; i < N; ++i) {
    auto iter = s.upper_bound({vals[i] - 1, MAX_N});
    if (iter == s.begin() || s.empty()) {
      colcount++;
      s.insert({vals[i], colcount});
    } else {
      --iter;
      int col = iter->second;
      s.erase(iter);
      s.insert({vals[i], col});
    }
  }
  printf("%d\n", colcount);
}
