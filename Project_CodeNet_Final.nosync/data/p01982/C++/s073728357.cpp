#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr)
#define digit(N) cout << fixed << setprecision((N))
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

bool is_uruu(vector<int> &a, int x)
{
    int index = -1, n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (x % a[i] == 0)
        {
            return (i + 1) % 2 == 1;
        }
    }

    return index == -1 && n % 2 == 0;
}

int main()
{
    int N, l, r;
    while (cin >> N >> l >> r)
    {
        if (N == 0)
            return 0;
        vector<int> a(N);

        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        int ans = 0;

        for (int i = l; i <= r; i++)
        {
            ans += is_uruu(a, i);
        }

        cout << ans << "\n";
    }
}
