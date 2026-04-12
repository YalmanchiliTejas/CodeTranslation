#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, a1, b1, sum, tmp;

int main(void) {
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    c *= 2;
    tmp = min(x, y);
    sum = min(c, a + b) * tmp;
    sum += min(a, c) * (x - tmp) + min(b, c) * (y - tmp);
    printf("%d\n", sum);
    return 0;
}
