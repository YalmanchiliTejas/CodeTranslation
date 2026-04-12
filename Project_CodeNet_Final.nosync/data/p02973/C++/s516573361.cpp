#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;

int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    for (int i = 0; i < N; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    reverse(a.begin(), a.end());
    cout << LIS(a) << endl;
}