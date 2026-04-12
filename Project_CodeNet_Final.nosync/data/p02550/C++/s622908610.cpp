#include <stdio.h>
int Pos[100000];
int main() {
    long long N, X, M;
    scanf("%lli%lli%lli", &N, &X, &M);

    /// Precalculate f(x)
    int F[100000];
    for (int i = 0; i < M; i++) {
        F[i] = (i * 1ll * i) % M;
    }

    /// Find the cycle
    int curA = F[X];
    Pos[X] = 1;
    long long sum_cycle = X, len_cycle = 1;
    while (!Pos[curA]) { /// While the element haven't showed up before
        //printf(" %i\n", curA);

        sum_cycle += curA;
        len_cycle++;
        Pos[curA] = len_cycle;
        curA = F[curA];
    }

    int el1_ofCycle = curA;

    /// Sum and length of the sequence part before the 1st cycle
    long long sum_start = 0;
    long long len_start = (Pos[el1_ofCycle] - 1);
    len_cycle -= len_start;
    for (int i = 0, a = X; i < len_start; i++, a = F[a]) {
        sum_cycle -= a;
        sum_start += a;
    }

    if (N < len_start) {
        /// N is too small
        curA = X;
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += curA;
            curA = F[curA];
        }
        printf("%lli", ans);
        return 0;
    }

    long long ans = sum_start;
    N -= len_start;
    ans += (N / len_cycle) * sum_cycle;

    curA = el1_ofCycle;
    N %= len_cycle;
    for (int i = 0; i < N; i++) {
        ans += curA;
        curA = F[curA];
    }
    printf("%lli", ans);
}
