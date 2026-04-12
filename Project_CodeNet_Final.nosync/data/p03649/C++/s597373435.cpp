#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 87;
LL a[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    LL ans = 0;
    bool OK = false;
    while (!OK) {
        OK = true;
        LL sum = 0;
        for (int i = 0; i < N; i++) {
            LL tmp = (a[i] / N);
            a[i] %= N;
            ans += tmp;
            a[i] -= tmp;
            sum += tmp;
        }
        for (int i = 0; i < N; i++) {
            a[i] += sum;
            //printf("i = %d a[i] = %lld\n", i, a[i]);
        }
        for (int i = 0; i < N; i++)
            if (a[i] >= N) OK = false;
    }
    printf("%lld\n", ans);
    return 0;
}
