#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<vector<long long>> dp;
const long long INF = 1LL << 60;

// [left, right) の状態からゲームを開始したときの X-Y を返す
long long func(int left, int right) {
  if (left == right) return dp.at(left).at(right) = 0;
  if (dp.at(left).at(right) != -INF) return dp.at(left).at(right);
  if ((N - (right - left)) % 2 == 0) {
    // 先手 (X-Y を最大化したい)
    long long res = -INF;
    res = max(res, A.at(left) + func(left + 1, right));  // 先頭をとる
    res = max(res, A.at(right - 1) + func(left, right - 1));  // 末尾をとる
    return dp.at(left).at(right) = res;
  }
  else {
    // 後手 (X-Y を最小化したい)
    long long res = INF;
    res = min(res, (-1) * A.at(left) + func(left + 1, right));
    res = min(res, (-1) * A.at(right - 1) + func(left, right - 1));
    return dp.at(left).at(right) = res;
  }
}

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  dp = vector<vector<long long>>(N+1, vector<long long>(N+1, -INF));
  cout << func(0, N) << endl;
}