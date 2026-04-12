#include <bits/stdc++.h>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define left privet6

using namespace std;
typedef long long ll;

const int max_n = 200011, log_n = 32, max_m = 111, mod = 1000000007, inf = 1000111222;

ll n, a[55];

ll check(int k) {
    /*for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;*/
    if (k == n - 1) {
        ll b = (a[0] - (n - 1));
        b = max(b, 0LL);
        for (int i =0 ; i < n; ++i) {
            a[i] -= b;
        }
        b *= n;
        /*for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;*/
        while (true) {
            if (a[n - 1] < n) {
                return b;
            }
            ++b;
            a[n - 1] -= n;
            for (int i = 0; i < n - 1; ++i) {
                ++a[i];
            }
            sort(a, a + n);
        }
    }
    ll b = min((a[k] - a[k + 1]) / (n + 1), a[0] / (n - k));
    for (int i = 0; i < n; ++i) {
        if (i <= k) {
            a[i] -= b * (n - k);
        } else {
            a[i] += b * (k + 1);
        }
    }
    sort(a, a + k + 2);
    return b * (k + 1) + check(k + 1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    cout << check(0) << endl;
    return 0;
}
