#include <cstdio>
#include <queue>

int n;
int main() {
  scanf("%d", &n);

  bool reversed = false;
  std::deque<int> que;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (!reversed) {
      que.push_back(a);
    } else {
      que.push_front(a);
    }
    reversed = !reversed;
  }

  if (!reversed) {
    auto i = que.begin();
    for (; (i + 1) != que.end(); i++) {
      printf("%d ", *i);
    }
    printf("%d\n", *i);
  } else {
    auto i = que.rbegin();
    for (; (i + 1) != que.rend(); i++) {
      printf("%d ", *i);
    }
    printf("%d\n", *i);
  }
  return 0;
}
