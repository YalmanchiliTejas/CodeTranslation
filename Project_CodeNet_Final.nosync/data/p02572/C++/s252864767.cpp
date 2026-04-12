#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<long> A(N);
    rep(i, N) cin >> A.at(i);

    long mod = pow(10, 9) + 7;

    long length = 0;
    rep(i, N)
    {
        length += A.at(i);
        length %= mod;
    }

    long area = length * length % mod;

    long diag = 0;
    rep(i, N)
    {
        diag += (A.at(i) * A.at(i)) % mod;
        diag %= mod;
    }

    if (area <= diag)
    {
        area += mod;
    }
    
    long ans = 0;
    if ((area - diag) % 2 == 0)
    {
        ans = (area - diag) / 2;
    }
    else
    {
        ans = (area - diag + mod) / 2;
    }

    cout << ans % mod << endl;

    return 0;
}
