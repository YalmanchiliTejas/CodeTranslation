#include <iostream>
#include <algorithm>

int N, M;
int num_cases = 0;
int adjacency_matrix[8][8] = {0};
int order_of_passage[8];

int main() {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    order_of_passage[i] = i;
  }
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    adjacency_matrix[a][b] = 1;
    adjacency_matrix[b][a] = 1;
  }
  
  do { // Is the case possible?
    bool can_pass = true; 
    for (int i = 0; i < N - 1; ++i) { // Does the cooresponding edge exist?
      if (adjacency_matrix[order_of_passage[i]][order_of_passage[i+1]] == 0) {
        can_pass = false;
        break;
      }
    }
    if (can_pass) ++num_cases;
  } while (std::next_permutation(order_of_passage + 1, order_of_passage + N));
  std::cout << num_cases << std::endl;
}