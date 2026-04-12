#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    int l = b[n / 2 - 1];
    int r = b[n / 2];
    for (int i = 0; i < n; ++i) {
        if (a[i] <= l) {
            cout << r << '\n';
        } else {
            cout << l << '\n';
        }
    }
    return 0;
}