#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> b(a);
  sort(b.begin(), b.end());
  multiset<int> left, right;
  for (int i = 0; i < n; ++i)
    (i < n / 2 ? left : right).insert(b[i]);
  for (int i = 0; i < n; ++i)
    if (left.find(a[i]) != left.end())
      printf("%d\n", *right.begin());
    else
      printf("%d\n", *left.rbegin());
  return 0;
}