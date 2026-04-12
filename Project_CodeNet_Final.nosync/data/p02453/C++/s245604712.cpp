#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << lower_bound(as.begin(), as.end(), k) - as.begin() << endl;
    }
}
