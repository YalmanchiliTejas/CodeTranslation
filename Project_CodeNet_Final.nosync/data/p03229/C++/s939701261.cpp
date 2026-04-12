#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<long> vin;
  long N;
  cin >> N;
  long vread;
  for (long i = 0; i < N; ++i) {
    cin >> vread;
    vin.push_back(vread);
  }
  sort(vin.begin(), vin.end());

  vector<long> coef;

  // でこぼこの形で2通り
  if (N % 2 == 0) {
    coef.push_back(1);
    coef.push_back(-1);
    for (long i = 0; i < N / 2; ++i) {
      coef.push_back(2);
    }
    for (long i = 0; i < (N - 2) / 2; ++i) {
      coef.push_back(-2);
    }
  } else {
    coef.push_back(-1);
    coef.push_back(-1);
    for (long i = 0; i < N / 2; ++i) {
      coef.push_back(2);
    }
    for (long i = 0; i < (N - 2) / 2; ++i) {
      coef.push_back(-2);
    }
  }

  long maxscore = 0;
  sort(coef.begin(), coef.end());
  long score = 0;
  for (long i = 0; i < N; ++i) {
    score += vin[i] * coef[i];
    maxscore = max(maxscore, score);
  }
  coef.clear();

  // 2通り目
  if (N % 2 == 0) {
    coef.push_back(1);
    coef.push_back(-1);
    for (long i = 0; i < N / 2; ++i) {
      coef.push_back(-2);
    }
    for (long i = 0; i < (N - 2) / 2; ++i) {
      coef.push_back(2);
    }
  } else {
    coef.push_back(1);
    coef.push_back(1);
    for (long i = 0; i < N / 2; ++i) {
      coef.push_back(-2);
    }
    for (long i = 0; i < (N - 2) / 2; ++i) {
      coef.push_back(2);
    }
  }

  sort(coef.begin(), coef.end());
  score = 0;
  for (long i = 0; i < N; ++i) {
    score += vin[i] * coef[i];
    maxscore = max(maxscore, score);
  }

  cout << maxscore << endl;

  return 0;
}