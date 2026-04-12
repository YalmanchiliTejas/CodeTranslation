#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int maxH = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x >= maxH) {
            res++;
        }
        maxH = max(maxH, x);
    }
    printf("%d\n", res);
    return 0;
}