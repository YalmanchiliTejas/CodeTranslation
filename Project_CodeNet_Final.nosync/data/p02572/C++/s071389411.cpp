#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    int64_t N, sum = 0;
    cin >> N;
    vector<int64_t> list(N);

    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        sum = (sum + list[i]) % MOD;
    }
    int ans = (sum * sum) % MOD;
    for (int i = 0; i < N; i++)
    {
        int64_t tmp = list[i] * list[i] % MOD;
        ans = (ans - tmp + MOD) % MOD;
    }
    if (ans % 2 == 0)
        cout << ans / 2;
    else
        cout << (ans + MOD) / 2;
}