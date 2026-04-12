// Copyright 2017 wu_qing
#include <cstdio>
int a, b, c, tot;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    tot = a * 100 + b *10 + c;
    if (tot % 4 == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
