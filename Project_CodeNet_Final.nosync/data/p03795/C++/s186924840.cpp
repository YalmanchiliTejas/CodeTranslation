#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    int res = 800*N - (N/15 * 200);

    printf("%d\n", res);


    return 0;
}