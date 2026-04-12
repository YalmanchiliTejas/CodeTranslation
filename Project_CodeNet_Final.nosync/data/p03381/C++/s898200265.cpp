#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000006];
int b[1001003];
int n, m, k;
int x, y, z;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
        int tmp = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        if (tmp > n / 2) {
            printf("%d\n", b[n / 2]);
        } else {
            printf("%d\n", b[n / 2 + 1]);
        }
    }
    return 0;
}