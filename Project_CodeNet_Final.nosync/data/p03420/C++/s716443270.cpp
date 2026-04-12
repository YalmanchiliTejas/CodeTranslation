#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    int N, K;
    while (~scanf("%d %d", &N, &K)) {
          LL ans = 0, pre_ans = 0;
          for (int b = K + 1; b <= N; b++) {
              ans += (LL)(N / b) * (b - K);
              int tmp = N % b;
              if (tmp && tmp >= K) {
                  ans += (tmp - K + 1);
                  if (K == 0) ans--;
              }
              // printf("b = %d cnt = %lld\n", b, ans - pre_ans);
              // printf("fst = %lld\n", (LL)(N / b) * (b - K));
              pre_ans = ans;
          }
          printf("%lld\n", ans);
    }
    return 0;
}
