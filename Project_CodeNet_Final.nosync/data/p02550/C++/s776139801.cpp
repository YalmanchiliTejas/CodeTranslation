#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>

signed main() {
    intmax_t N, X, M;
    scanf("%jd%jd%jd", &N, &X, &M);

    const size_t L = 35;
    std::vector<std::vector<intmax_t>> nxt_num(L + 1, std::vector<intmax_t>(M, 0));
    std::vector<std::vector<intmax_t>> nxt_sum(L + 1, std::vector<intmax_t>(M, 0));
    for (intmax_t n = 0; n < M; ++n) {
        nxt_num[0][n] = (n * n) % M;
        nxt_sum[0][n] = n;
    }
    for (size_t i = 0; i < L; ++i) {
        for (intmax_t n = 0; n < M; ++n) {
            nxt_num[i + 1][n] = nxt_num[i][nxt_num[i][n]];
            nxt_sum[i + 1][n] = nxt_sum[i][n] + nxt_sum[i][nxt_num[i][n]];
        }
    }

    size_t i = 0;
    intmax_t cur = X;
    intmax_t res = 0;
    while (N > 0) {
        if (N & 1) {
            res += nxt_sum[i][cur];
            cur = nxt_num[i][cur];
        }
        N >>= 1;
        ++i;
    }

    printf("%jd\n", res);
    return 0;
}
