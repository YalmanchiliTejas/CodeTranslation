#include <bits/stdc++.h>

int r, g, b;

int main() {

    scanf("%d%d%d", &r, &g, &b);

    if ((100*r + 10*g + b) % 4) {
        // 余りがあるとき => true
        printf("NO\n");
    } else {
        // 余りがないとき0 => False
        printf("YES\n");
    }

    return 0;
}