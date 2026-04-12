#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    int n, l, r;
    while (cin >> n >> l >> r and n and l and r) {
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int ans = 0;
        for (int x=l; x<=r; ++x) {
            bool ok = false;
            rep(i, n) {
                if (x%a[i] == 0) {
                    if (i%2 == 0) ans++;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                if (n%2 == 0) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

