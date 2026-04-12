#include <stdio.h>
#define MAX_N 200010

int a[MAX_N];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (n % 2) {
            if (i % 2) a[n / 2 + (i + 1) / 2] = t;
            else a[n / 2 - i / 2] = t;
        }
        else {
            if (i % 2) a[n / 2 - (i + 1) / 2] = t;
            else a[n / 2 + i / 2] = t;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
