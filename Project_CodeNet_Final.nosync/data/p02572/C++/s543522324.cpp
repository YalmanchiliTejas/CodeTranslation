#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long> A(N);
    long mod = 1e+9 + 7;

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    long ans = 0;
    long mult = A.at(N - 1);
    for (int i = N - 2; i >= 0; i--)
    {
        ans = (ans % mod) + ((A.at(i) * mult) % mod);
        mult += A.at(i);
        mult %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}
