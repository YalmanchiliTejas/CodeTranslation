#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x: a) {
        cin >> x;
    }
    long long res = 0;
    for (int c = 1; c < n-1; c++) {
        long long tmp = 0;
        for (int k = 0; (k+1)*c <=n-1; k++) {
            int A = n-1 - k*c;
            int B = A - c;
            if ((n-1)%c == 0 && 2*k > (n-1)/c - 1) {
                break;
            }
            if (B <= 0) break;
            tmp += 0ll + a[A] + a[k*c];
            res = max(res, tmp);
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
