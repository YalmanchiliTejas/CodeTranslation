#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    vector<vector<ll>> v(2);
    rep(i, N / 2) {
        v[0].push_back(A[i]);
        v[1].push_back(A[N - 1 - i]);
    }

    ll ans = v[1][0] - v[0][0];
    rep(i, N / 2 - 1) {
        ans += abs(v[0][i] - v[1][i + 1]) + abs(v[1][i] - v[0][i + 1]);
    }
    if (N != 1 && N % 2 == 1) {
        ans += max(A[N / 2] - v[0][N / 2 - 1], v[1][N / 2 - 1] - A[N / 2]);
    }

    cout << ans << endl;
}