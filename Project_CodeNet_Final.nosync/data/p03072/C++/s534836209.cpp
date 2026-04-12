#include <stdio.h>

#define MAX_N 20

int main() {
        int i;
        int N;
        int H[MAX_N] = { 0 };
        int cnt;

        scanf("%d", &N);

        for (i = 0; i < N; i++) scanf("%d", &H[i]);

        for (i = 1, cnt = 1; i < N; i++) {
                if (H[i] >= H[i-1]) {
                        cnt++;
                } else {
                        H[i] = H[i-1];
                }
        }

        printf("%d\n", cnt);

        return 0;
}
