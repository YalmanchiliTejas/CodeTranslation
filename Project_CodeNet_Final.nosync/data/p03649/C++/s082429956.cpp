#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, a[55], sum;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (ll i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    sort(a, a + n, greater<ll>());
    ll k = 0;
    if (sum - n * n > 0) {
        ll moves = sum - n * n;
        k = moves;
        ll mx = 0;
        for (int i = 0; i < n; ++i)
            a[i] += moves, mx = max(mx, a[i]);
        ll L = 0, R = mx;
        ll new_moves;
        while (L < R) {
            ll mid = (L + R) / 2;
            new_moves = 0;
            for (int i = 0; i < n; ++i)
                new_moves += max(0LL, a[i] - mid) / (n + 1);
            if (new_moves <= moves)
                R = mid;
            else
                L = mid + 1;
        }
        new_moves = 0;
        for (int i = 0; i < n; ++i)
            new_moves += max(0LL, a[i] - L) / (n + 1), a[i] -= max(0LL, a[i] - L) / (n + 1) * (n + 1);
        moves -= new_moves;
        sort(a, a + n, greater<ll>());
        while (moves--) {
            a[0] -= n + 1;
            sort(a, a + n, greater<ll>());
        }
    }

    while (a[0] >= n) {
        a[0] -= n;
        for (int i = 1; i < n; ++i)
            ++a[i];
        sort(a, a + n, greater<ll>());
        ++k;
    }

    cout << k << endl;

    return 0;
}
