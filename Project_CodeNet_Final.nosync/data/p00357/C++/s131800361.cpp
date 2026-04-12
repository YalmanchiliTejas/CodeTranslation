#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 300000;

int main() {
    int n;
    cin >> n;
    ll d[n];
    for (int i = 0; i < n; i++) cin >> d[i];
    ll md = 0;
    for (int i = 0; i < n; i++) {
        if (i <= md) md = max(md, i + (d[i] / 10));
    }
    if (md < n - 1) {
        cout << "no" << endl;
        return 0;
    }
    md = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (md <= i) md = min(md, i - (d[i] / 10));
    }
    if (md > 0) cout << "no" << endl;
    else cout << "yes" << endl;
}
