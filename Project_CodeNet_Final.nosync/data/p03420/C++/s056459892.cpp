#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<ll, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}







void _main() {
        int n, k; cin >> n >> k;
        ll ans = 0;
        for (int a = 1; a <= n; a++) {
                int low = k;
                int high = a - 1;
                if (low > high) {
                        continue;
                }

                int blocks = n / a;
                int rem = n % a;
                ans += blocks * (high - low + 1) + max(0, min(high, rem) - low + 1) - (low == 0);
        }


        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}