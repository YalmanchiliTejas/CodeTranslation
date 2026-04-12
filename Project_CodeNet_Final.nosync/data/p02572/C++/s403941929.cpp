#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    long A[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    const long modnum = pow(10, 9) + 7;
    long A_sum[N + 1];
    A_sum[N + 1] = 0;
    for (int i = 0; i <= N; i++)
    {
        A_sum[N - i] = (A_sum[N - i + 1] + A[N - i]) % modnum;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = ans + ((A[i] * A_sum[i + 1]) % modnum);
    }
    ans = ans % modnum;
    cout << ans << "\n";
}
