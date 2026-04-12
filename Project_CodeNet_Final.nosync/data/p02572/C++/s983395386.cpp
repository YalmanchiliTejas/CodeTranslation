#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const size_t L = 1000000000 + 7;

    size_t N;
    vector<size_t> A;

    cin >> N;
    A.resize(N);
    for (size_t i = 0; i < N; ++i) { cin >> A[i]; }

    size_t sum = 0;
    size_t sq_sum = 0;

    for (size_t i = 0; i < N; ++i)
    {
        sum = (sum + A[i]) % L;
        size_t temp = (A[i] * A[i]) % L;
        sq_sum = (sq_sum + temp) % L;
    }

    size_t tmp = (sum * sum) % L;
    if (tmp < sq_sum) { tmp += L; }
    tmp -= sq_sum;

    const size_t Inv = (1000000000 + 8) / 2;   // 2 の逆数 mod L
    cout << (tmp * Inv) % L << endl;


    // cout << (sum * sum - sq_sum) / 2 << endl;


    return 0;
}
