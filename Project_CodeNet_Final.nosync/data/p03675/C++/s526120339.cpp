#include <bits/stdc++.h>

using namespace std;

const int MAX = 2 * 1e5 + 10;
long long a[MAX];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", a + i);
  }
  list<long long> vec;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) vec.emplace_front(a[i]);
    else vec.emplace_back(a[i]);
  }
  if (N % 2 == 0) {
    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
      printf("%lld ", *it);
    }
    puts("");
  } else {
    for (auto it = vec.begin(); it != vec.end(); it++) {
      printf("%lld ", *it);
    }
    puts("");
  }
}
