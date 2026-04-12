#include<bits/stdc++.h>

using namespace std;

int n;

deque<int> deq;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    if(i % 2 == 0) {
      deq.push_back(x);
    }else {
      deq.push_front(x);
    }
  }

  if(n % 2 == 1) {
    reverse(deq.begin(), deq.end());
  }

  for(int x : deq) {
    printf("%d ", x);
  }
  return 0;
}