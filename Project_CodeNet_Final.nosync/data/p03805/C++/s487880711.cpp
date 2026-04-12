#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

//using integer = unsigned long long;
using integer = signed long long;

typedef struct {
  int a;
  int b;
} node;

int main(void) {
  int N, M; 
  std::cin >> N >> M;

  int line[N+1][N+1] = {0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      line[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    line[a-1][b-1] = 1;
    line[b-1][a-1] = 1;
  }

  std::vector<int> v(N-1);
  for (int i = 1; i < N; i++) {
    v[i-1] = i;
  }

#if 0
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      //std::cout << " " << line[i][j];
      line[i][j] = 0;
    }
    //std::cout << std::endl;
  }
#endif

  int count = 0;
  do {
    bool ok = true;
    if (line[0][v[0]] == 0) {
      continue;
    }
    for (int i = 1; i < N-1; i++) {
      if (line[v[i-1]][v[i]] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      count++;
    }
  } while (std::next_permutation(v.begin(), v.end()));

  std::cout << count << std::endl;

  return 0;
}
