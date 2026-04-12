//In the name of Allah

#include <bits/stdc++.h>

using namespace std;

const int N = 223456;

int a[N];
deque < int > b;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i % 2) {
      b.push_back(a[i]);
    } else {
      b.push_front(a[i]);
    }
  }
  if (n % 2) {
    for (auto it = b.begin(); it != b.end(); it++) {
      cout << *it << ' ';
    }
  } else {
    for (auto it = b.rbegin(); it != b.rend(); it++) {
      cout << *it << ' ';
    }
  }
  return 0;
}