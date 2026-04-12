#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int a = 0, x, ans = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &x);
        if(a <= x) ans ++;
        a = max(a, x);
    }
    printf("%d\n", ans);
    return 0;
}
