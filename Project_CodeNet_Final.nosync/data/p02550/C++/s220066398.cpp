#include <bits/stdc++.h>

using namespace std;

int main() {
  int64_t N, X, M;
  cin >> N >> X >> M;
  N--;
  vector<int64_t> visit(M, -1);
  vector<int64_t> R(M, -1);
  visit[X] = 0;
  int64_t prev = X;
  R[0] = X;

  int64_t loop_first = -1;
  int64_t loop_second = -1;
  {
    int64_t turn = 1;
    while (true) {
      R[turn] = R[turn - 1] * R[turn - 1] % M;
      if (visit[R[turn]] >= 0) {
        loop_first = visit[R[turn]];
        loop_second = turn;
        break;
      }
      visit[R[turn]] = turn;
      turn++;
    }
  }

  int64_t answer = 0;
  for (int64_t turn = 0; turn < min(N + 1, (int64_t )loop_first); turn++) {
    answer += R[turn];
  }
  int64_t loop_size = loop_second - loop_first;
  int64_t loop_count = (N - loop_first + 1) / (loop_size);
  int64_t sum_one_loop = 0;
  for (int i = loop_first; i < loop_second; i++) {
    sum_one_loop += R[i];
  }
  answer += sum_one_loop * loop_count;
  {
    int64_t turn = loop_first + loop_count * loop_size;
    int64_t r = R[loop_first];
    for (; turn <= N; turn++) {
      answer += r;
      r = r * r % M;
    }
  }
  cout << answer << endl;

  return 0;
}
