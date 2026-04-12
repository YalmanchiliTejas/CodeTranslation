#include <cstdio>

int main()
{
    int N;
    int H[100];
    if (scanf("%d", &N) == EOF) return -1;
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &H[i]) == EOF) return -1;
    }

    int answer = 0;
    int highest = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] < highest) continue;
        answer++;
        highest = H[i];
    }
    printf("%d\n", answer);
}
