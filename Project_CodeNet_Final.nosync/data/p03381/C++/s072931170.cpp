// 7/17
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    vector<int> Y(N);
    rep(i, N) Y[i] = X[i];
    sort(Y.begin(), Y.end());    

    int z = N/2;
    int prev, after;
    prev = Y[z - 1];
    after = Y[z];

    rep(i, N) {
        if (X[i] == after) {
            cout << prev << endl;
        } else if (X[i] <= prev) {
            cout << after << endl;
        } else {
            cout << prev << endl;
        }
    }

    return 0;
}