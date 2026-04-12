#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(20);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = i - 1; j >= 0; j--) {
            ok &= (a[j] <= a[i]);
        }
        res += ok;
    }
    cout << res << "\n";
}
