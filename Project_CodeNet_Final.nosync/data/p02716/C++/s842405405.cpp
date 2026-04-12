#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= a; i--)
#define RF0(i,b) RFO(i,0,b)
#define F first
#define S second

#if 1
i64 calc(const vector<int>& A) {

  int N = A.size();

  // 偶数indexにはそこまでの偶数indexの数値の合計、
  // 奇数indexには（以下略）を入れる
  vector<i64> sums;
  sums.reserve(N);
  sums.push_back(A[0]);
  sums.push_back(A[1]);
  FOR(i, 2, N) {
    sums.push_back(A[i] + sums[i - 2]);
  }

  i64 result = INT64_MIN;
  int hn = N / 2;

  // 1個足したあとは必ず1回休み、を繰り返すが
  // フリーの休み回数がNが偶数のとき1、奇数のとき2あると考える
  // A. "足す"の位置を休みにすること
  // B. 休みになった"足す"は、1つ奥にずれる。それ以降もずれる

  if (N % 2 == 0) {
    // 偶数個

    // 休み1回目
    FOR(i, 0, hn + 1) {

      // この休み位置における合計
      i64 sum = 0;

      if (i > 0) {
        // ～ i +偶数index
        sum += sums[(i - 1) * 2];

        // i ～ -奇数index
        sum -= sums[i * 2 - 1];
      }

      // i ～ +奇数index
      sum += sums[N - 1];

      if (sum > result) result = sum;
    }
  }
  else {
    // 奇数個

    // 休み1回目
    /*
    FOR(i, 0, hn + 1) {
      // 休み2回目 (i == j もありうる)
      FOR(j, i, hn + 1) {

        // この休み回数での合計を計算
        i64 sum = 0;

        if (i > 0) {
          // ～ i +偶数index
          sum += sums[(i - 1) * 2];

          // i ～ j -奇数index
          sum -= sums[i * 2 - 1];
        }
        if (j > 0) {
          // i ～ j +奇数index
          sum += sums[j * 2 - 1];
        }

        // j ～ -偶数index
        sum -= sums[j * 2];

        // j ～ +偶数index
        sum += sums[N - 1];

        //cout << sum << " ";
        if (sum > result) {
          result = sum;
        }
      }
    }
    */

    // 休み位置に対しての、sumの変動をあらかじめ計算
    vector<i64> ic(hn + 1);
    FOR(i, 1, hn + 1) {
      ic[i] = sums[(i - 1) * 2] - sums[i * 2 - 1];
    }
    deque<pair<int, i64>> jc(hn + 1);  // 2回目の休み位置は、indexつきの配列にする
    F0R(j, hn + 1) {
      i64 c = 0;
      if (j > 0) c += sums[j * 2 - 1];
      c -= sums[j * 2];
      jc[j] = { j, c };
    }

    sort(jc.begin(), jc.end(), [](const pair<int, i64>& a, const pair<int, i64>& b) {
      return a.second > b.second;
    });

    F0R(i, hn + 1) {
      i64 sum = ic[i];
      // この1回目の休み位置に対する、最良な2回目の休み位置を求める
      while (jc.begin()->first < i) {
        jc.pop_front();
      }
      sum += jc.begin()->second;

      if (sum > result) result = sum;
    }

    result += sums[N - 1];
  }

  return result;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

#if 1

  // Solve
  vector<int> A(N);
  F0R(i, N) {
    cin >> A[i];
  }

  cout << calc(A);

#else

  // Generate test data
  vector<int> A(N);
  F0R(i, N) {
    //cout << (i + 1) << ' ';
    A[i] = -1000000000;
  }

  cout << calc(A);
#endif
}
#endif
