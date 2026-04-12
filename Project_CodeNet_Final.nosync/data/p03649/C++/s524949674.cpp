#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector <i64> luat, v;

bool cbin(i64 p, i64 x);

i64 n;

int main()
{
    i64 ans(0);
    cin >> n;
    v.resize(n);
    for (i64 i(0); i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (i64 i(n - 1); i >= 0; i--) {
        i64 p(0), q(1ll << 55);
        while (q) {
            if (cbin(i, p + q))
                p += q;
            q /= 2ll;
        }
        for (i64 j(i); j < n; j++)
            v[j] += (n - i - 1) * p - 1ll * n * p;
        for (i64 j(0); j < i; j++)
            v[j] += 1ll * (n - i) * p;
        ans += p * (n - i);
    }

    while (v[n - 1] >= n) {
        v[n - 1] -= n;
        for (i64 i(0); i < n - 1; i++)
            v[i]++;
        sort(v.begin(), v.end());
        ans++;
    }

    cout << ans;

    return 0;
}

bool cbin(i64 p, i64 x)
{
    if (v[p] - n * x + (n - p - 1) * x < n)
        return false;
    if (p && v[p] - n * x + (n - p - 1) * x < v[p - 1] + (n - p) * x)
        return false;
    return true;
}
