#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<long> A(N);
    rep(i, N) cin >> A.at(i);

    long ans = 0;

    long ai;
    long mod = pow(10, 9) + 7;

    long as = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        ai = A.at(i);
        as += A.at(i + 1);
        as %= mod;
        ans += (ai * as) % mod;
    }

    cout << ans % mod << endl;

    return 0;
}