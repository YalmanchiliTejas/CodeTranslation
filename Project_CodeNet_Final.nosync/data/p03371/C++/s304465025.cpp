#include<stdio.h>
int main() {
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    c = c * 2;
    int ans;
    if (c <= a && c <= b) {
        if (x > y)
            ans = x * c;
        else
            ans = y * c;
    }
    else if (c <= a && c > b) {
        if (x > y)
            ans = x * c;
        else
            ans = x * c + (y - x)*b;
    }
    else if (c > a && c <= b) {
        if (x < y)
            ans = y * c;
        else
            ans = y * c + (x - y)*a;
    }
    else if (c < a + b) {
        if (x > y)
            ans = y * c + (x - y)*a;
        else
            ans = x * c + (y - x)*b;
    }
    else
        ans = a * x + b * y;
    printf("%d\n", ans);
    return 0;
}