#include <bits/stdc++.h>
using namespace std;

vector<long long> All;
vector<long long> P;

long long dfs(int level, long long remain) {

  if (level == 0){
    return 1;
  }

  long long answer = 0;
 
  // 最初のパン
  if (1 <= remain) {
    remain--;
  }

  // X-1 
  if (1 <= remain) {
    if (All[level - 1] <= remain) {
      remain -= All[level - 1];
      answer += P[level - 1];
    } else {
      answer += dfs(level - 1, remain);
      remain = 0;
    }
  }

  // 真ん中のパティ
  if (1 <= remain) {
    remain--;
    answer++;
  }

  // X-1 
  if (1 <= remain) {
    if (All[level - 1] <= remain) {
      remain -= All[level - 1];
      answer += P[level - 1];
    } else {
      answer += dfs(level - 1, remain);
      remain = 0;
    }
  }

  // 最後のパン
  if (1 <= remain) {
    remain--;
  }

  return answer;
}

int main() {

  int N;
  long long X;
  cin >> N >> X;

  All.resize(N);
  P.resize(N);

  All[0] = 1;
  P[0] = 1;

  for (int i = 1; i < N; i++) {
    All[i] = All[i - 1] * 2 + 3;
    P[i] = P[i - 1] * 2 + 1;
  }

  long long answer = dfs(N, X);

  cout << answer << endl;

  return 0;

}