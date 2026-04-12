#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long mod = 1000000000 + 7;
    cin >> N;
    long long A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    long long sum_mod[N + 2];
    sum_mod[N+1] = 0;
    for (int i = N; i > 0; i--)
    {
        sum_mod[i] = sum_mod[i+1] + A[i - 1];
        sum_mod[i] %= mod;
    }
    long long ans = 0;
    for (int i = 0; i < N-1; i++)
    {
        ans += (A[i]*sum_mod[i+2])%mod;
    }
    cout << ans % mod << endl;
}