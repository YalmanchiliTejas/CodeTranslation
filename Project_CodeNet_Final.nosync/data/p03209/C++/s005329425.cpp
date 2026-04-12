#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

ll len(int n) { return (1LL << (n + 2)) - 3; }

ll find(int n, ll x)
{
    if (n == 0) return 1;

    const ll mid = (len(n) + 1) / 2;
    if (x == 1) {
        return 0;
    } else if (x < mid) {
        return find(n - 1, x - 1);
    } else if (x == mid) {
        return find(n - 1, x - 1) + 1;
    } else if (x < len(n)) {
        return find(n - 1, len(n-1)) + 1 + find(n - 1, x - mid);
    } else {
        return 2 * find(n - 1, len(n-1)) + 1;
    }
}

int main()
{
    int n; cin >> n;
    ll x; cin >> x;
    cout << find(n, x) << endl;
    return 0;
}