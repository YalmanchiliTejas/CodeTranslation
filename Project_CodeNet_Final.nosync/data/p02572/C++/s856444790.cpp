/**
https : //atcoder.jp/contests/abc177/tasks/abc177_c
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<uint64_t> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    const uint64_t base = 1000000007;
    uint64_t sum = 0;

    int64_t sum1d = 0;
    for (int i = 0; i < n; ++i)
    {
        sum1d += a[i] % base;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        const auto ai = a[i];
        sum1d -= ai;
        if (sum1d < 0) sum1d += base;
        sum1d %= base;
        sum += sum1d * ai;
        sum %= base;
    }

    cout << sum << endl;
}
