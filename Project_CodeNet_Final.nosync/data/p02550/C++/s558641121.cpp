#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  long long N, X, M; cin >> N >> X >> M;
  map<long long, long long> Map;
  
  long long A = X;
  long long count = 2;
  long long count_; // サイクル周期
  long long res;
  bool flag = true;
  Map[A] = 1;
  while (flag) {
    A = (A * A) % M;
    if (Map[A] >= 1) {
      flag = false;
      count_ = count - Map[A];
      res = A;
    }
    else Map[A] = count;
    count++;
  }
  long long start = Map[res]; // サイクルはじめ
  if (N - start + 1 <= count_) {
    long long sum = X;
    for (long long i = 0; i < N - 1; i++){
      X = (X * X) % M;
      sum += X;
    }
    cout << sum << endl;
  }
  else {
    long long sum = X;
    if (start == 1) sum = 0;
    for (long long i = 0; i < start - 2; i++){
      X = (X * X) % M;
      sum += X;
    }
    long long sum_ = 0;
    if (start == 1){
      sum_ += X;
      for (long long i = 0; i < count_ - 1; i++){
        X = (X * X) % M;
        sum_ += X;
      }
    }
    else {
      for (long long i = 0; i < count_; i++){
        X = (X * X) % M;
        sum_ += X;
      }
    }
    sum += ((N - start + 1) / count_) * sum_;
    for (long long i = 0; i < N - ((start - 1) + ((N - start + 1) / count_) * count_); i++){
      X = (X * X) % M;
      sum += X;
    }
    cout << sum << endl;
  }
}