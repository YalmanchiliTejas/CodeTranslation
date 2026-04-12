#include <iostream>
#include <vector>

int main()
{
    long long N;
    std::cin >> N;
    std::vector<long long> A(N);
    std::vector<long long> S(N + 1);
    // [a_0, a_1, a_2, a_3]
    // a_0*a_1 + a_0*a_2 + a_0*a_3 + a_1*a_2 + a_1*a_3 + a_2*a_3
    // = a_0 * (a_1 + a_2 + a_3) + a_1 * (a_2 + a_3) + a_2 * a_3
    S[0] = 0;
    for (long long i = 0; i < N; i++)
    {
        std::cin >> A[i];

        S[i + 1] = (S[i] + A[i]) % 1000000007;
    }
    // S_0 = 0
    // S_1 = a_0
    // S_2 = a_0 + a_1
    // S_2 - S_0 = a_0 + a_1
    // S_j - S_i = a_i + a_(i+1) + ... + a_(j-1)
    long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        // a_i * (a_(i+1) + a_(i+2) + ... + a_(N-1))
        long long tmp = S[N] - S[i + 1];
        if (tmp < 0)
            tmp += 1000000007;
        tmp = (A[i] * tmp) % 1000000007;
        ans = (ans + tmp) % 1000000007;
    }
    std::cout << ans << std::endl;
}