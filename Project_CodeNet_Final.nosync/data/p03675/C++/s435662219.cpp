#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> b(2 * N);

    int l = N, r = N;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        if (N % 2 == i % 2) {
            b.at(--l) = a;
        } else {
            b.at(r++) = a;
        }
    }

    for (int i = l; i < r; ++i) {
        if (i > l) cout << ' ';
        cout << b.at(i);
    }
    cout << endl;

    return 0;
}