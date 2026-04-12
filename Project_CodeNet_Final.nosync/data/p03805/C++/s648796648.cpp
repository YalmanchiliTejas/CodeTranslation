#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int search(const std::vector<bool>& adj, std::vector<int>& cand,
    int start, int end) {
  int cnt = 0;
  if (start == end) {
    cnt++;
  } else {
    for (int i=start; i<end; i++) {
      if (adj[cand[start-1]*end+cand[i]]) {
        std::swap(cand[start], cand[i]);
        cnt += search(adj, cand, start+1, end);
        std::swap(cand[start], cand[i]);
      }
    }
  }
  return cnt;
}

int main() {
  int N, M, a, b;
  std::cin >> N >> M;
  std::vector<bool> adj(N*N, false);
  for (int i=0; i<M; i++) {
    std::cin >> a >> b;
    adj[(a-1)*N+(b-1)] = true;
    adj[(b-1)*N+(a-1)] = true;
  }
  
  std::vector<int> cand(N);
  std::iota(std::begin(cand), std::end(cand), 0);
  std::cout << search(adj, cand, 1, N) << std::endl;
}