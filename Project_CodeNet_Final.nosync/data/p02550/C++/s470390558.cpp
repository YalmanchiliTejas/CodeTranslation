// https://atcoder.jp/contests/abc179/tasks/abc179_e
// 解説放送

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, x, m;
    cin >> n >> x >> m;

    vector<long> ids(m, -1);
    vector<long> xs;

    long len = 0;
    long tot = 0;
    while (ids[x] == -1)
    {
        xs.push_back(x);
        ids[x] = len;
        len++;
        tot += x;
        x = (x * x) % m;
    }

    long loop_len = len - ids[x];
    long loop_sum = 0;
    for (long i = ids[x]; i < len; i++)
    {
        loop_sum += xs[i];
    }

    long ans = 0;
    if (n < len)
    {
        for (long i = 0; i < n; i++)
        {
            ans += xs[i];
        }
    }
    else
    {
        ans += tot;
        n -= len;
        ans += (n / loop_len) * loop_sum;
        n %= loop_len;
        for (long i = 0; i < n; i++)
        {
            ans += xs[ids[x] + i];
        }
    }
    cout << ans << endl;
    return 0;
}