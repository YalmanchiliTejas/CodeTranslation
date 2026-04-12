// ABC154 E - Almost Everywhere Zero
// 問題URL
// https://atcoder.jp/contests/abc154/tasks/abc154_e

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>
#include <iomanip>

using namespace std;

const int64_t N_MAX = 100;
int64_t pascal_delta[N_MAX][N_MAX];

// combinationを計算
void comb_init()
{
  for (int i = 0; i < N_MAX; i++) {
    pascal_delta[i][0] = 1;
    pascal_delta[i][i] = 1;
  }
  for (int j = 1; j < N_MAX; j++) {
    for (int k = 1; k < j; k++) {
      pascal_delta[j][k] = (pascal_delta[j - 1][k - 1] + pascal_delta[j - 1][k]);
    }
  }
  return;
}

int64_t comb(int n, int r)
{
  if (n < r)
    return 0;
  else
    return pascal_delta[n][r];
}

int main()
{
  char N[100] = {0};
  int digit_num_of_N;
  string string_n;
  int K;

  cin >> string_n >> K;

  digit_num_of_N = string_n.size();
  for (int i = 0; i < string_n.size(); i++) {
    N[i] = string_n[string_n.size() - 1 - i];
  }

  comb_init();

  // Nの桁数より小さい桁数の数字で条件を満たすものの数
  int sum = 0;
  for (int digit_num = 1; digit_num <= digit_num_of_N - 1; digit_num++) {
    sum += comb(digit_num - 1, K - 1) * pow(9, K);
  }

  // Nの桁数と同じ桁数の数字について
  // 最上位の位がNの最上位の位の数字より小さい
  sum += comb(digit_num_of_N - 1, K - 1) * pow(9, K - 1) * (N[digit_num_of_N - 1] - '0' - 1);

  // 上の桁から見て2番目に0以外の数字が出てくる桁は？
  int digit_num_of_N_second = digit_num_of_N;
  for (int i = digit_num_of_N - 2; i >= 0; i--) {
    if (N[i] != '0') {
      digit_num_of_N_second = i + 1;
      break;
    }
  }

  if (digit_num_of_N_second != digit_num_of_N) {
    sum += comb(digit_num_of_N_second - 1, K - 2) * pow(9, K - 2) * (N[digit_num_of_N_second - 1] - '0' - 1);
    sum += comb(digit_num_of_N_second - 1, K - 1) * pow(9, K - 1);
  }
  else {
    if (K == 1) sum += 1;
    cout << sum << endl;
    return 0;
  }

  // 上の桁から見て3番目に0以外の数字が出てくる桁は？
  int digit_num_of_N_third = digit_num_of_N_second;
  for (int i = digit_num_of_N_second - 2; i >= 0; i--) {
    if (N[i] != '0') {
      digit_num_of_N_third = i + 1;
      break;
    }
  }

  if (digit_num_of_N_third != digit_num_of_N_second) {
    sum += comb(digit_num_of_N_third - 1, K - 3) * (N[digit_num_of_N_third - 1] - '0');
    sum += comb(digit_num_of_N_third - 1, K - 2) * pow(9, K - 2);
  }
  else {
    if (K == 2) sum += 1;
  }

  cout << sum << endl;

  return 0;
}
