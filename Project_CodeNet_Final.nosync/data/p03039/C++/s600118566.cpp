#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

const u_int64_t D = 1'000'000'007LL;

u_int64_t xgdf(u_int64_t a, u_int64_t b, int64_t *co)
{
    if (b == 0)
    {
        return a;
    }

    int64_t c = a / b;
    int64_t old[4];
    old[0] = co[0];
    old[1] = co[1];
    old[2] = co[2];
    old[3] = co[3];

    co[0] = 0LL * old[0] + 1LL * old[1];
    co[1] = 1LL * old[0] - c * old[1];
    co[2] = 0LL * old[2] + 1LL * old[3];
    co[3] = 1LL * old[2] - c * old[3];

    return xgdf(b, a % b, co);
}

u_int64_t hoge(const u_int64_t N)
{
    return N * (N - 1) * (N + 1) / 6;
}

u_int64_t comb(const u_int64_t a, const u_int64_t b)
{
    u_int64_t numerator = 1;
    u_int64_t denominator = 1;

    for (u_int64_t i = b; i > 0; i--)
    {
        numerator = ((a - i + 1) * numerator) % D;
        denominator = (i * denominator) % D;
    }

    int64_t co[4];
    co[0] = 1LL;
    co[1] = 0LL;
    co[2] = 0LL;
    co[3] = 1LL;

    xgdf(denominator, D, co);
    int64_t inv_d = (co[0] + D) % D;

    return numerator * inv_d;
}

int main()
{
    u_int64_t N, M, K;

    cin >> N >> M >> K;

    const u_int64_t c = comb(N * M - 2, K - 2) % D;
    const u_int64_t m2 = (M * M) % D;
    const u_int64_t n2 = (N * N) % D;
    const u_int64_t xx = hoge(N) % D;
    const u_int64_t yy = hoge(M) % D;

    const u_int64_t sx = (((m2 * xx) % D) * c) % D;
    const u_int64_t sy = (((n2 * yy) % D) * c) % D;

    const u_int64_t sum = (sx + sy) % D;

    cout << (u_int64_t)sum << endl;
    return 0;
}
