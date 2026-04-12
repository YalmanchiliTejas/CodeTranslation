#include <math.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int N;
  cin >> N;
  vector<int> H(N);

  rep(i, N) { cin >> H.at(i); }
  int count_ = 0;
  rep(i, N) {
    int a = H.at(N - i - 1);
    bool b = true;
    rep(j, N - i) {
      if (a < H.at(j)) {
        b = false;
        break;
      }
    }
    if (b == true) count_++;
  }
  cout << count_ << endl;
}
