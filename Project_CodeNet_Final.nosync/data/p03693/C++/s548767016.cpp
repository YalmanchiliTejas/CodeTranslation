#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int r, g, b, n;
    scanf("%d %d %d", &r, &g, &b);
    n = 100 * r + 10 * g + b;
    if (n % 4 == 0) {
        printf("YES");
    }
    else {
        printf("NO");
    }
}
