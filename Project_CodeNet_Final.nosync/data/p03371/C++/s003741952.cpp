#include <cstdio>
#include <cstdlib>

int main() {
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

    //先处理成对的棋盘
    int common = x;
    if (x > y) {
        common = y;
    }

    // common * (a + b)
    // common * c * 2
    int sum1 = common * c * 2;
    if (common * c * 2 > common * (a + b)) {
        sum1 = common * (a + b);
    }

    // 先处理剩下的棋盘
    int left = x - common;
    int price = a;
    if (x - common == 0) {
        left = y - common;
        price = b;
    }
    // left * price
    // left * 2 * c
    int sum2 = left * price;
    if (left * price > left * c * 2) {
        sum2 = left * c * 2;
    }
    printf("%d", sum1 + sum2);
    return EXIT_SUCCESS;
}