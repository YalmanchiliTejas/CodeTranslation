#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, h, m = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);
        if (m <= h) ++ans, m = h;
    }
    printf("%d\n", ans);
    return 0;
}
