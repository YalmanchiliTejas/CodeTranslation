#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
bool edge[10][10];

void input() {
  std::cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int s, t;
    std::cin >> s >> t;
    edge[s-1][t-1] = true;
    edge[t-1][s-1] = true;
  }
}

int main() {
  std::memset(edge, 0, sizeof(edge));
  input();
  int cnt = 0;
  std::vector<int> v(N);
  for (int i = 0; i < N; i++) v[i] = i;
  
  do {
    int i = 0;
    while (edge[v[i]][v[i+1]]) {
      i++;
      if (i > N-2) break;
    }
    if (i == N-1) cnt++;
  } while (std::next_permutation(v.begin()+1, v.end()));
  
  std::cout << cnt << std::endl;
  
  
  return 0;
}
