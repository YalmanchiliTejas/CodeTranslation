#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, t, sum, minv, maxv;
    for (; ;) {
        scanf("%d", &n);
        if (n == 0) break;
        sum = maxv = 0, minv = 1001;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            sum+=t;
            maxv = max(maxv, t);
            minv = min(minv, t);
        }
        printf("%d\n", (sum-maxv-minv)/(n-2));
    }
    return 0;
}

