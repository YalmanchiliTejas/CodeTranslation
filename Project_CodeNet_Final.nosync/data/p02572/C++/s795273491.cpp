#include <iostream>

using namespace std;

#define MOD (int)(1e9 + 7)

int A[200'001];

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    long long sum1 = 0ll;
    for (int i = 0; i < N; ++i)
        sum1 = (A[i] + sum1) % MOD;
    long long sum2 = 0ll;
    for (int i = 0; i < N; ++i)
        sum2 = (((long long)A[i] * A[i]) % MOD + sum2) % MOD;

    long long val = ((sum1 * sum1 % MOD - sum2) % MOD);
    if (val < 0)
        val += MOD;
    cout << (val * ((MOD >> 1) + 1)) % MOD;

    return 0;
}