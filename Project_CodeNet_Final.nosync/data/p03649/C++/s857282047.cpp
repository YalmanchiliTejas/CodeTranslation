#include<bits/stdc++.h>
using namespace std;

const int MAX = 55;
long long A[MAX], B[MAX];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
    long long cnt, ans, maxa;
    cnt = ans = 0;
    maxa = N;
    while (maxa >= N) {
        maxa = 0;
        for (int i = 0; i < N; i++) {
            B[i] = A[i] / N;
            cnt += B[i];
            A[i] = A[i] % N;
        }
        for (int i = 0; i < N; i++) {
            A[i] += cnt - B[i];
            B[i] = 0;
            maxa = max(maxa, A[i]);
        }
        ans += cnt;
        cnt = 0;
    }
    printf("%lld\n", ans);
    return 0;
}
