#include <cstdio>
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
 
int main(void) {
    int N;
    scanf("%d", &N);
    int s[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &s[i]);
    }
 
    long long ans = 0;
    for (int c = 1; c < N; ++c) {
        long long f = 0;
        for (int l = 0, r = N - 1; l + c < N - 1; l += c, r -= c) {
            if ((N - 1) % c == 0 && l >= r) { break; }
            f += s[l] + s[r];
            ans = MAX(ans, f);
        }
    }
 
    printf("%lld\n", ans);
 
    return 0;
}