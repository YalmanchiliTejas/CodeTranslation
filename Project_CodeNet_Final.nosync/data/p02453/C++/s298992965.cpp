#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
    }
    return 0;
}
