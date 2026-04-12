#include <bits/stdc++.h>

using namespace std;

#define reps(i, n, m) for (int i = (int) (n); i < (int) (m); i++)
#define rep(i, n) reps(i, 0, (n))
#define all(v) (v).begin(), (v).end()

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int q; cin >> q;
    while (q--) {
        int a; cin >> a;
        cout << lower_bound(all(v), a) - v.begin() << endl;
    }
}
