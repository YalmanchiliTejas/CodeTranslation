#include<iostream>
using namespace std;

long long elem_cnt[60];
long long patties[60];

long long cnt(long long num, int level) {
  if (level == 0) {
    return 1;
  } else {
    if (num == 1) {
      return 0;
    } else if (1 < num && num < elem_cnt[level] / 2 + 1) {
      return cnt(num - 1, level - 1);
    } else if (num == elem_cnt[level] / 2 + 1) {
      return patties[level - 1] + 1;
    } else if (elem_cnt[level] / 2 + 1 < num && num < elem_cnt[level]) {
      return patties[level - 1] + 1 + cnt(num - ( elem_cnt[level] / 2 + 1 ), level - 1);
    } else if (num == elem_cnt[level]) {
      return patties[level - 1] * 2 + 1;
    }
  }
}

int main() {
  int N;
  cin >> N;
  long long X;
  cin >> X;

  elem_cnt[0] = 1;
  patties[0] = 1;
  for (int i = 0; i <= N ; i++) {
    elem_cnt[i + 1] = 2 * elem_cnt[i] + 3;
    patties[i + 1] = 2 * patties[i] + 1;
  }
  cout << cnt(X, N) << endl;
}
