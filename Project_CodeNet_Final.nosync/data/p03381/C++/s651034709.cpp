#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X(N);
    for (auto &x : X) cin >> x;
    vector<int> XX = X;
    sort(XX.begin(), XX.end());
    int L = XX.at(N / 2 - 1);
    int R = XX.at(N / 2);

    for (auto &x : X) {
        if (x <= L) {
            cout << R << endl;
        } else {
            cout << L << endl;
        }
    }

    return 0;
}