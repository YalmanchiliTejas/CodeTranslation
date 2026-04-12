#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, m, s = 0; cin >> n >> x >> m;
    deque<ll> w(m), a;
    for (int i = 0; i < n; i++) {
        if (x == 0) {
            break;
        }
        if (w[x]) {
            ll r = s; n -= i;
            while (a.front() != x) {
                a.pop_front();
            }
            s = accumulate(a.begin(), a.end(), 0ll);
            i = a.size(); r += n / i * s;
            for (int j = 0; j < n % i; j++) {
                r += a[j];
            }
            return cout << r << endl, 0;
        }
        s += x;
        w[x] = 1;
        a.push_back(x);
        x = x * x % m;
    }
    cout << s << endl;
    return 0;
}
