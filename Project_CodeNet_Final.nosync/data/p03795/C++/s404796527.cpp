#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;
    int N;

    scanf("%d", &N);

    x = 800*N;

    y = 200*(N/15);

    printf("%d\n",x-y);

    return 0;
}
