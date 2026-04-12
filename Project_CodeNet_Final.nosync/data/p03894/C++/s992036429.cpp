#include <bits/stdc++.h>
using namespace std;

int N;
int Q;
int idx;
int cups[114514];
set<int> cnt;

int main() {
  scanf("%d%d", &N, &Q);
  for (int i=0; i<N; i++) cups[i] = i;
  idx = 0;
  cnt.insert(0);
  cnt.insert(1);
  for (int i=0; i<Q; i++) {
    int a;
    int b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    swap(cups[a], cups[b]);
    if (idx == b) idx = a;
    else if (idx == a) idx = b;
    cnt.insert(cups[idx]);
    if (idx-1 >= 0) cnt.insert(cups[idx-1]);
    if (idx+1 < N) cnt.insert(cups[idx+1]);
  }

  printf("%d\n", (int)cnt.size());
}
